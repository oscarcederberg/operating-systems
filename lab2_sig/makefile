CC		= gcc
CFLAGS		= -g

all: exitcode loop simple

exitcode: exitcode.c
	$(CC) $(CFLAGS) -o $@.out $^

loop: loop.c
	$(CC) $(CFLAGS) -o $@.out $^

simple: simple.c
	$(CC) $(CFLAGS) -o $@.out $^

clean:
	rm -f exitcode.out loop.out simple.out