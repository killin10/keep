/*
 * @file iovmax.c
 * @brief limit on writev/readv
 *
 * @version 1.0
 * @date Fri Aug 24 09:46:06 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#define __need_IOV_MAX

#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void
print_limit()
{
    printf("IOV_MAX %d\n", IOV_MAX);
    printf("_SC_IOV_MAX %d\n", sysconf(_SC_IOV_MAX));
}

void
try_iovmax()
{
    int rc = 0;
    int i = 0;

    int fd = open("/dev/null", O_WRONLY);
    if (fd < 0) {
        fprintf(stderr, "open /dev/null error, %s\n", strerror(errno));
        return;
    }

    for (i = 0; ; ++i) {
        struct iovec *vecs = (struct iovec *) malloc(i * sizeof(struct iovec));
        memset(vecs, 0, i * sizeof(struct iovec));

        rc = writev(fd, vecs, i);

        if (-1 == rc) {
            fprintf(stderr, "writev() error, %s\n", strerror(errno));
            break;
        }
    }

    close(fd);

    printf("iovmax %d\n", i - 1);
}

int
main(int argc, char *argv[])
{
    print_limit();

    try_iovmax();

    return 0;
}

