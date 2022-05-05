#define _POSIX_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int alarm_called = 0;

void iterate() {
    printf("iteration starting...\n");
    unsigned long int i = 0;
    while (!alarm_called) {
        i++;
    }
    printf("iterations: %lu\n", i);
}

void alarm_handler(int signum) {
    printf("alarm!\n");
    alarm_called = 1;
}

int main() {
    signal(SIGALRM, alarm_handler);

    alarm(10);
    iterate();
}