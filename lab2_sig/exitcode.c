#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char *argv[] )  {
    if (argc < 2) {
        printf("no argument supplied...\n");
        return 0;
    }

    char* program = argv[1];
    
    int pid = fork();
    if (pid < 0) {
        printf("parent: could not fork\n");
        exit(1);
    }

    if (pid == 0) {
        char* args[] = {program, NULL};
        execv(program, args);
    } else {
        printf("pid:\t\t\t%d\n", pid);
        
        int status;
        int terminated_pid;
        do {
            terminated_pid = waitpid(pid, &status, WNOHANG);
        } while (terminated_pid != pid);

        if (WIFEXITED(status)) {
            printf("exit:\t\t\tnormal\n");
            printf("status:\t\t\t%d\n", WEXITSTATUS(status));
        } else {
            printf("exit:\t\t\tabnormal\n");
        }

        if (WIFSIGNALED(status)) {
            printf("signaled:\t\tyes\n");
            printf("signal:\t\t\t%d\n", WTERMSIG(status));
        } else {
            printf("signaled:\t\t\tno\n");
            printf("signal:\t\t\tn/a\n");
        }
    }
}