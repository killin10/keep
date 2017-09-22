CFLAGS=-g -O0

BINS=client server

all: $(BINS)

server: server.o
	$(CC) $(CFLAGS) -o $@ $?

client: client.o
	$(CC) $(CFLAGS) -o $@ $?

clean:
	rm -rf *.o $(BINS)


