#define _POSIX_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void wait_seconds(unsigned int x) {
    printf("loop start\n");
    for (unsigned int i = 0; i < x; ++i) {
        printf("%d...\n", i + 1);
        sleep(1);
    }
}

void print_blocked(sigset_t* set) {
    printf("\nsignals blocked:\n");
    for (int i = 0; i < SIGRTMAX; i++){
        if (sigismember(set, i) == 1) {
            printf("%d blocked.\n", i);
        }
    }
}

int main() {
   	sigset_t set1, set2;
	sigfillset(&set1);
    sigemptyset(&set2);

    sigprocmask(SIG_BLOCK, &set1, NULL);

    wait_seconds(10);

    sigpending(&set2);

    print_blocked(&set2);
}