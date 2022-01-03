# 42-minishell
Minishell will introduce you to the world of shells, which provide a convenient text interface to interact with your system. Shells might seem very easy to understand but have very specific and defined behaviour in almost every single case, most of which will need to be handled properly.

| External functs.    | Description | Form | Header |
| --- | ----------------------- | ---------- | ---------- |
| **readline**| Prints a prompt, receives a single line of text input from the user, and returns it. readline() return value is malloc() assigned by. | `char *readline (char *prompt)`   | `#include <readline/readline.h>`  |
| **rl_on_new_line**| Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. | `int rl_on_new_line (void)`   | `#include <readline/readline.h>`  |
| **rl_replace_line**| Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared. | `void rl_replace_line (const char *text, int clear_undo)`   | `#include <readline/readline.h>`  |
| **rl_redisplay**| If non-zero, Readline will call indirectly through this pointer to update the display with the current contents of the editing buffer. By default, it is set to rl_redisplay, the default Readline redisplay function. | `void rl_redisplay(void)`   | `#include <readline/readline.h>`  |
| **add_history**| Place string at the end of the history list. The associated data field (if any) is set to NULL. If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, the oldest history entry is removed. Place the string at the end of the history list. The relevant data field is set to NULL. When the number of history items exceeds the maximum, old items are deleted. | `add_history(const char *string)`   | `#include <readline/readline.h>`  |
| **wait3**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait3(int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **wait4**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **signal**| Set up signal handling. | `void (*signal(int sig, void (*func)(int)))(int)`   | `#include <signal.h>`  |
| **kill**| Unlike the kill command, which kills a process in the shell, it sends a signal to the process. Sending SIGKILL to a process acts like a shell command kill. | `int kill(pid_t pid, int sig)`   | `#include <signal.h>`  |
