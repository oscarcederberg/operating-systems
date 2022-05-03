CC		= gcc
CFLAGS		= -g

all: exitcode loop loop1 simple

exitcode: exitcode.c
	$(CC) $(CFLAGS) -o $@.out $^

loop: loop.c
	$(CC) $(CFLAGS) -o $@.out $^

loop1: loop1.c
	$(CC) $(CFLAGS) -o $@.out $^

simple: simple.c
	$(CC) $(CFLAGS) -o $@.out $^

clean:
	rm -f exitcode.out loop.out loop1.out simple.out