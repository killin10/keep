/*
 * @file server.c
 * @brief foo server
 *
 * @version 1.0
 * @date Wed Nov 21 00:27:08 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define LISTEN_BACKLOG      50
#define REUSEADDR_OFF       0
#define REUSEADDR_ON        1
#define REUSEADDR_KEEP      2
#define CLOSE_SOCKET_OFF    0 
#define CLOSE_SOCKET_ON     1
#define BUFFER_SIZE         4096

void usage(const char *bin_name);

void
usage(const char *bin_name)
{
    fprintf(stderr, "usage: %s local_ip local_port "
            "reuse_addr(0/1/2) close_socket(0/1)\n",
            bin_name);
    fprintf(stderr, "\treuse_addr: 0/1 - disable/enable SO_REUSEADDR\n");
    fprintf(stderr, "\t              2 - keep system setting\n");
}

int
main(int argc, char *argv[])
{
    if (5 != argc) {
        usage(argv[0]);
        return -1;
    }

    const char *ip = argv[1];
    uint16_t port = atoi(argv[2]);
    int reuse_addr = atoi(argv[3]);
    int close_socket = atoi(argv[4]);

    // socket

    int sock = socket(PF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        fprintf(stderr, "socket error, %s\n", strerror(errno));
        return -1;
    }

    int rc = 0;

    // set SO_REUSEADDR

    if (REUSEADDR_KEEP != reuse_addr) {
        rc = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
                        &reuse_addr, sizeof(int));

        if (rc < 0) {
            fprintf(stderr, "setsockopt(SO_REUSEADDR) error, %s\n",
                    strerror(errno));
            close(sock);
            return -1;
        }
    }

    // bind and listen

    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(struct sockaddr_in));

    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(port);

    rc = inet_pton(AF_INET, ip, &(local_addr.sin_addr));

    if (rc < 0) {
        fprintf(stderr, "inet_pton error, %s\n", strerror(errno));
        close(sock);
        return -1;
    }

    rc = bind(sock, (struct sockaddr *) &local_addr,
              sizeof(struct sockaddr_in));

    if (rc < 0) {
        fprintf(stderr, "bind error, %s\n", strerror(errno));
        close(sock);
        return -1;
    }

    rc = listen(sock, LISTEN_BACKLOG);

    if (rc < 0) {
        fprintf(stderr, "listen error, %s\n", strerror(errno));
        close(sock);
        return -1;
    }

    // accept

    int conn = 0;

    socklen_t addr_len = 0;
    struct sockaddr_in remote_addr;

    char remote_ip[INET_ADDRSTRLEN];
    const char *rip = NULL;

    for (; ;) {
        addr_len = sizeof(struct sockaddr_in);
        conn = accept(sock, (struct sockaddr *) &remote_addr, &addr_len);

        if (conn < 0) {
            fprintf(stderr, "accept error, %s\n", strerror(errno));
            continue;
        }

        rip = inet_ntop(AF_INET, &(remote_addr.sin_addr),
                        remote_ip, INET_ADDRSTRLEN);

        if (NULL == rip) {
            fprintf(stderr, "inet_ntop error, %s\n", strerror(errno));
            memset(remote_ip, 0, INET_ADDRSTRLEN);
        }

        printf("connection from %s:%" PRIu16 "\n",
               remote_ip, ntohs(remote_addr.sin_port));

        if (CLOSE_SOCKET_OFF == close_socket) {
            char buf[BUFFER_SIZE];
            rc = read(conn, buf, BUFFER_SIZE);

            if (0 == rc) {
                printf("connection close by remote %s:%" PRIu16 "\n",
                       remote_ip, ntohs(remote_addr.sin_port));

            } else if (rc < 0) {
                fprintf(stderr, "read socket error, %s\n", strerror(errno));
                close(conn);
                return -1;

            } else {
                // never reach here in this small test
            }

            close(conn);

        } else {
            close(conn);
        }
    }

    return 0;
}


