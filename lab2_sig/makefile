CC			= gcc
CFLAGS		= -g

all: exitcode loop loop1 loop2 loop3 simple

exitcode: exitcode.c
	$(CC) $(CFLAGS) -o $@.out $^

loop: loop.c
	$(CC) $(CFLAGS) -o $@.out $^

loop1: loop1.c
	$(CC) $(CFLAGS) -o $@.out $^

loop2: loop2.c
	$(CC) $(CFLAGS) -o $@.out $^

loop3: loop3.c
	$(CC) $(CFLAGS) -o $@.out $^

simple: simple.c
	$(CC) $(CFLAGS) -o $@.out $^

clean:
	rm -f exitcode.out loop.out loop1.out loop2.out loop3.out simple.out