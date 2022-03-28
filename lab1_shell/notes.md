## access
int **access**(const char *pathname, int mode);

access() checks whether the calling process can access the file pathname.

## close
int **close**(int fd);

close() closes a file descriptor, so that it no longer refers to any file and may be reused.

## dup2
int **dup2**(int oldfd, int newfd);

The dup() system call creates a copy of the file descriptor oldfd, using the lowest-numbered unused file descriptor for the new descriptor.

## execv
int **execv**(const char *pathname, char *const argv[]);

The exec() family of functions replaces the current process image with a new process image.

The char *const argv[] argument is an array of pointers to null-terminated strings that represent the argument list available to the new program.  The first argument, by convention, should point to the filename associated with the file being executed.  The array of pointers must be terminated by a null pointer.

## exit
void **_exit**(int status);

The function _exit() terminates the calling process "immediately". Any open file descriptors belonging to the process are closed.

## fork
pid_t **fork**(void);

fork() creates a new process by duplicating the calling process.  The new process is referred to as the child process.  The calling process is referred to as the parent process.

## open
int **open**(const char *pathname, int flags);  
int **open**(const char *pathname, int flags, mode_t mode);

The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().  

The return value of open() is a file descriptor, a small, nonnegative integer that is used in subsequent system calls (read(2), write(2), lseek(2), fcntl(2), etc.) to refer to the open file. The file descriptor returned by a successful call will be the lowest-numbered file descriptor not currently open for the process.

## pipe
int **pipe**(int pipefd\[2\]);

pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication. The array pipefd is used to return two file descriptors referring to the ends of the pipe. pipefd\[0\] refers to  the
read end of the pipe. pipefd\[1\] refers to the write end of the pipe. Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of  the pipe.

## wait & waitpd
pid_t **wait**(int *wstatus);

The wait() system call suspends execution of the calling thread until one of its children  terminates.

pid_t waitpid(pid_t pid, int *wstatus, int options);

The waitpid() system call suspends execution of the calling thread until a child specified by pid argument has changed state.  By default, waitpid() waits only for terminated children, but this behavior is modifiable  via
the options argument, as described below.

The value of pid can be:

< -1   meaning wait for any child process whose process group ID is equal to the absolute value of pid.

-1     meaning wait for any child process.

0      meaning  wait  for  any child process whose process group ID is equal to that of the calling process at
        the time of the call to waitpid().

\> 0    meaning wait for the child whose process ID is equal to the value of pid.

## chdir & getcwd
int **chdir**(const char *path);  
int **fchdir**(int fd);

chdir() changes the current working directory of the calling process to the directory specified in path.

fchdir() is identical to chdir(); the only difference is that the directory is given as an open file descriptor.

char \***getcwd**(char *buf, size_t size);  
char \***getwd**(char *buf);

These functions return a null-terminated string containing an absolute pathname that is the current working directory of the calling process. The pathname is returned as the function result and via the argument buf, if present.

The getcwd() function copies an absolute pathname of the current working directory to the array pointed to by buf, which is of length size.