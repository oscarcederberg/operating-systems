#define _POSIX_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigusr2(int sig) {
    printf("sigusr2 handled\n");
}

void handle_sigint(int sig) {
    printf("sigint handled\n");
    
    struct sigaction sa1, sa2;
    sa1.sa_handler = SIG_IGN;
    sa2.sa_handler = &handle_sigusr2;
    sigaction(SIGUSR1, &sa1, NULL);
    sigaction(SIGUSR2, &sa2, NULL);

    while (1) {}
}

int main() {
    struct sigaction sa;
    sa.sa_handler = &handle_sigint;
    sigaction(SIGINT, &sa, NULL);
    
    while (1) {}
}