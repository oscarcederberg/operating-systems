machine : machine.c
	gcc -std=c99 -Wall -Wno-unused -pedantic -Werror $< -o $@

debug : machine.c
	gcc -std=c99 -g -O0 -Wall -DDEBUG machine.c -o machine

run-fifo : machine
	./machine --fifo fac.s

run-sc : machine
	./machine --second-chance fac.s

run-opt : machine
	./machine --optimal fac.s

run-all : run-fifo run-sc run-opt

clean :
	rm -f machine
