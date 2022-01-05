# 42-minishell
Minishell will introduce you to the world of shells, which provide a convenient text interface to interact with your system. Shells might seem very easy to understand but have very specific and defined behaviour in almost every single case, most of which will need to be handled properly.

| External functs.    | Description | Form | Header |
| --- | ----------------------- | ---------- | ---------- |
| **readline**| Prints a prompt, receives a single line of text input from the user, and returns it without line breaks. If prompt is NULL or the empty string, no prompt is issued.  The line returned is allocated with malloc(); | `char *readline (char *prompt)`   | `#include <readline/readline.h>`  |
| **rl_on_new_line**| Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. | `int rl_on_new_line (void)`   | `#include <readline/readline.h>`  |
| **rl_replace_line**| Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared. | `void rl_replace_line (const char *text, int clear_undo)`   | `#include <readline/readline.h>`  |
| **rl_redisplay**| If non-zero, Readline will call indirectly through this pointer to update the display with the current contents of the editing buffer. By default, it is set to rl_redisplay, the default Readline redisplay function. | `void rl_redisplay(void)`   | `#include <readline/readline.h>`  |
| **add_history**| Place string at the end of the history list. The associated data field (if any) is set to NULL. If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, the oldest history entry is removed. Place the string at the end of the history list. The relevant data field is set to NULL. When the number of history items exceeds the maximum, old items are deleted. | `add_history(const char *string)`   | `#include <readline/readline.h>`  |
| **wait3**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait3(int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **wait4**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **signal**| Set up signal handling. | `void (*signal(int sig, void (*func)(int)))(int)`   | `#include <signal.h>`  |
| **kill**| Unlike the kill command, which kills a process in the shell, it sends a signal to the process. Sending SIGKILL to a process acts like a shell command kill. | `int kill(pid_t pid, int sig)`   | `#include <signal.h>`  |
| **getcwd**| Copies the absolute path of the current working directory to buf and returns a pointer to buf. If buf is NULL, space is allocated and size is ignored. If the buffer is small, an error may occur, so set it large. | `char *getcwd(char *buf, size_t size)`   | `#include <unistd.h>`  |
| **chdir**| Change the current working directory. You must have execute permission on the (change directory) directory. The beginning of path must not be ' \ '. | `int chdir(const char *path)`   | `#include <unistd.h>`  |
| **stat**| A function to get the status or information of a file, such as the size, permission, creation date, and last modification date of the file. If a file that is a symbolic link is passed to path, information of the original file is obtained. lstatThe function gets information about the symbolic link file itself. | `int stat(const char *path, struct stat *buf)`   | `#include <sys/stat.h>`  |
| **lstat**| It has the same function as the stat function. If a file that is a symbolic link is passed to the path, information about the file that is a symbolic link is obtained. | `int lstat(const char *path, struct stat * buf)`   | `#include <sys/stat.h>`  |
| **fstat**| A function to obtain the status of a file or information about the file, such as the size of the opened file, the authority of the file, the creation date and time of the file, and the last modified date. | `int fstat(int fd, struct stat *buf)`   | `#include <sys/stat.h>`  |
| **open**| Open the file for use. fopen()is a function provided by the C library and open()is a function provided by Linux. | `int open (const char *FILENAME, int FLAGS[, mode_t MODE])`   | `#include <fcntl.h>`  |
| **unlink**| Delete the link. | `int unlink(const char *path)`   | `#include <unistd.h>`  |
| **close**| open() Close the file opened by the function. | `int close(int fd)`   | `#include <unistd.h>`  |
| **read**| open() Read the contents of the file opened with the function. | `ssize_t read(int fd, void *buf, size_t n)`   | `#include <unistd.h>`  |
| **write**| open() Writes to a file opened with a function. | `ssize_t write(int fd, const void *buf, size_t n)`   | `#include <unistd.h>`  |
| **malloc**| Memory is dynamically allocated. | `void *malloc(size_t size)`   | `#include <stdlib.h>`  |
| **waitpid**| wait() like a function, it waits until the child process exits. The difference is that the wait() function is released from waiting when any of the child processes exit, but waits waitpid()until the specific child process exits. | `pid_t waitpid(pid_t pid, int *status, int options)`   | `#include <sys/wait.h>`  |
| **wait**| Waits until the child process task is finished. | `pid_t wait(int *status)`   | `#include <sys/wait.h>`  |
| **free**| malloc()The calloc()memory allocated by or is returned to the system.| `void free(void *ptr)`   | `#include <stdlib.h>`  |
| **pipe**| Create a pipe and assign the fd value for the pipe to fildes.| `int pipe(int fildes[2])`   | `#include <unistd.h>`  |
| **dup**| Make a copy of the file descriptor. The read/write pointers of the original descriptor and the copied descriptor are shared.| `int dup(int fildes)`   | `#include <unistd.h>`  |
| **dup2**| Copy the file descriptor of fd and give it to fd2 as well. (so that fd2 also points to the file pointed to by fd)| `int dup2(int fildes, int fildes2)`   | `#include <unistd.h>`  |
| **execve**| Changes the process that called the execve function to a new process.| `int execve(const char *path, char *const argv[], char *const envp[])`   | `#include <unistd.h>`  |
| **fork**| Creates a copy process for the currently running process.| `pid_t fork(void)`   | `#include <unistd.h>`  |
| **strerror**| Creates a copy process for the currently running process.| `char *strerror(int errnum)`   | `#include <string.h>`  |
| **errno**| Returns: the last error number that occurred| `extern int errno`   | `#include <sys/errno.h>`  |
| **exit**| Terminate the process.| `void exit(int status)`   | `#include <stdlib.h>`  |
| **opendir**| Specified Directory Used to search for files and directories in a specific directory.| `DIR *opendir(const char *filename)`   | `#include <dirent.h>`  |
| **readdir**| opendir(). For a directory opened by, get information about all files and directories in it.| `struct dirent *readdir(DIR *dirp)`   | `#include <dirent.h>`  |
| **closedir**| opendir(). Close the directory opened with.| `int closedir(DIR *dirp)`   | `#include <dirent.h>`  |
| **isatty**|Determining whether a valid terminal type device is referenced for  `fd` | `int isatty(int fd)`   | `#include <unistd.h>`  |
| **ttyname**| isatty. If the function finds a valid device, it returns the device name.| `char *ttyname(int fd)`   | `#include <unistd.h>`  |
| **ttyslot**| When a device file is found, its unique number is returned.| `int ttyslot(void)`   | `#include <unistd.h>`  |
| **ioctl**| Functions to obtain hardware control and status information| `int ioctl(int fd, unsigned long request, ...)`   | `#include <sys/ioctl.h>`  |
| **getenv**| Find the desired variable value from the list of environment variables.| `char *getenv(const char *name)`   | `#include <stdlib.h>`  |
| **tcgetattr**| Store terminal properties for terminal file fd in termios_p| `int tcgetattr(int fd, struct termios *termios_p)`   | `#include <termios.h>`  |
| **tcsetattr**| set terminal properties for terminal file fd| `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)`   | `#include <termios.h>`  |
| **tgetent**| Extracts the input of the terminal name into the buffer `bp` .| `int tgetent(char *bp, const char *name)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetflag**| Boolean information on whether is present in the terminal entry `id` .| `int tgetflag(char *id)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetnum**| Numeric information about whether is present in the terminal entry `id` .| `int tgetnum(char *id)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetstr**| String information on whether is present in the terminal entry `id` .| `char *tgetstr(char *id, char **area)`   | `#include <curses.h>` `#include <term.h>` |
| **tgoto**| Instantiates the parameter to the specified function. The return value is tputspassed to the function.| `char *tgoto(const char *cap, int col, int row)`   | `#include <curses.h>` `#include <term.h>` |
| **tputs**| output string returned by `tgetstr`| `int tputs(const char *str, int affcnt, int (*putc)(int))`   | `#include <curses.h>` `#include <term.h>` |


## ctrl+c
* `INT` signal (SIGINT).
* Basically, it is responsible for terminating the process.

## ctrl+z
* `TSTP` signal (SIGTSTP).
* Basically, it is responsible for terminating the process.

## ctrl+\
* `QUIT` signal (SIGQUIT).
* Basically, it serves to dump the core after terminating the process.

## ctrl+t
* `INFO` signal (SIGINFO).
* If supported by the command, by default the operating system displays information about the command being executed.
* It is not supported by all types of Unix.

## SIGHUP
* Occurs when the connection with the terminal is lost.
* By default, the process is terminated.
* Unix signal: 1.

## SIGINT
* Occurs when an interrupt occurs.
* By default, the process is terminated.
* Unix signal: 2.
* Interrupt signal input from keyboard (ctrl_c)

## SIGQUIT
* Terminal exit signal.
* It exits with a core dump
* Unix signal: 3.
* Execution stop signal input from keyboard (ctrl+\)

## SIGKILL
* Terminate the process unconditionally.
* It cannot be ignored and cannot be controlled.
* Unix signal: 9.

## SIGSEGV
* Occurs when a process references the wrong memory.
* It exits with a core dump.
* Unix signal: 11.

## SIGSTOP
* Process interruption.
* It is not terminated and has no control.
* Unix signal: 17.
* A signal (ctrl+z) that waits to resume execution after stopping execution.
