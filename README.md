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


## READLINE
readline — это библиотека GNU для чтения пользовательского ввода. Он поддерживает все виды возможностей редактирования строки, которые пользователь может использовать для редактирования строки ввода. Например, пользователь может перемещать курсор в разные позиции в строке и изменять части входной строки.\
Флаг для компиляции -lreadline\
Команды для изменения строки при вводе:
* CNTRL-a   move curser to begining of input string
* CNTRL-e   move curser to end of input string
* CNTRL-b   move curser back one character
* CNTRL-f   move curser forward one character
* CNTRL-d   delete the character under the curser
* CNTRL-k   kill the string from the curser to the end of the line
* CNTRL-l   clear the screen and re-print the prompt and input string at the top

Обработка EOF в возвращаемом значении readline делится на два случая. Если встречается EOF, но строки для обработки раньше нет, возвращается NULL. Если встречается EOF, но есть строка, которую нужно обработать раньше, EOF обрабатывается как символ новой строки, и строка возвращается соответствующим образом.
Причина, по которой функция readline похожа на функцию get_next_line, но не одна и та же, заключается в том, что среди функций readline есть функция, поддерживающая редактирование vi или emacs. Например, как упоминалось выше, чтобы воспроизвести случай, когда есть строка, которую нужно обработать при обнаружении EOF, вы должны ввести Ctrl + D после ввода строки.

#### * rl_on_new_line `int rl_on_new_line(void)`

Функция rl_on_new_line используется при уведомлении связанных с обновлением функций в каталоге readline о том, что курсор переместился на следующую строку через символ новой строки. Поскольку это функция для целей уведомления, функция rl_on_new_line напрямую не воспроизводит символ новой строки. Поэтому функция rl_on_new_line используется после вывода символа новой строки.
Функции, связанные с обновлением, включают rl_redisplay.
Если в выполнении функции rl_on_new_line нет проблем, возвращается 0, иначе возвращается -1.

#### * rl_replace_line `void rl_replace_line(const char *text, int clear_undo)`

Функция rl_replace_line использует переменную с именем rl_line_buffer. Функции в каталоге readline могут использовать глобально предоставленные переменные из каталога readline, и rl_line_buffer является одной из них. Использовать rl_replace_line можно разными способами, но его также можно использовать для сброса и инициализации rl_line_buffer. В частности, в этом случае его можно использовать в ситуации, когда принимается сигнал.

#### * rl_redisplay `(void rl_redisplay(void)`

Функция rl_redisplay также использует переменную с именем rl_line_buffer, как и функция rl_replace_line. Если используется функция rl_redisplay, значение rl_line_buffer, введенное и поддерживаемое пользователем, отображается с подсказкой. В это время значение приглашения используется как строка, переданная в качестве приглашения функции readline.
Если вы хотите изменить приглашение, вы можете изменить его с помощью специальной функции, существующей в каталоге readline.

#### * add_history `void add_history(const char *line)`

add_history — это функция, которая позволяет вам вернуть строку, введенную пользователем во время базовой операции функции readline. Строка, записанная как line, которая является аргументом add_history, может быть вызвана во время выполнения функции readline с помощью клавиш со стрелками вверх и вниз.
В случае использования встроенного каталога readline в серии Unix возвращаемое значение имеет тип int. Если в выполнении функции нет проблем, возвращается 0, иначе возвращается -1.

# Cursor control using termcap library(описание характеристик терминалов)
Если вы пишете что-то в терминале, то нужно перемещать курсор, чтобы редактировать ввод. Однако, если вы нажимаете клавиши со стрелками для перемещения курсора в терминале в настройках по умолчанию, курсор не перемещается. Чтобы управлять курсором с помощью клавиш со стрелками, вам нужно изменить параметры [терминала](https://hyeonski.tistory.com/6?category=471028).
Любая программа работает на разных видах терминалов и ей не важно как на конкретном терминале очистить экран или какой код выдает клавиша "стрелка вверх". Для этого существует специальная "база данных свойств терминалов" - termcap. Каждый тип терминала имеет своё название и перечень [свойств](http://www.linuxlib.ru/Linux/syscons/termcap.html).

&= это способ установить определенный бит равным 0 в целом числе, представляющем битовое [поле](https://stackoverflow.com/questions/20948621/what-does-mean).\
Структура [termios](https://man7.org/linux/man-pages/man3/termios.3.html)

```
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	int c = 0;

	while (read(0, &c, sizeof(c)) > 0)
	{
		printf("keycode: %d\n", c);
       		c = 0; // очистка буфера
	}
}
```
Если запустить, то увидим код клавиш(1, 2, 3, 4, 5, ctrl + D)\
\
![Screenshot from 2022-01-18 13-33-22](https://user-images.githubusercontent.com/84707645/149921222-05ab9242-0234-40b8-b4be-faa72999bfc3.png)\
read() считает sizeof(int), чтобы получить value(?) клавиши стрелочки, для каждой ОС он разный, но в случае стрелочек в 64-битной среде macOS/Linux это 4 байта. (Для специальных клавиш, таких как ctrl+up, иногда необходимо прочитать больше, чем 4 байта.)\
\
Для управления курсором следует использовать библиотеку `termcap`. Настройка использования библиотеки начинается с функции tgetent().

#### * tgetent `int tgetent(char *bp, const char *name)`
Tgetent пoмeщaeт в бyфep bp инфopмaцию o тepминaлe соответствующую имени. Как правило, значение, присвоенное имени, использует тип терминала, назначенный в качестве переменной среды TERM. В этом случае обычно присваивается значение NULL, поскольку указатель буфера, называемый bp, является игнорируемым аргументом. Bp дoлжeн yкaзывaть нa мaccив cимвoлoв paзмepoм 1024 бaйтa и дoлжeн coxpaнятьcя в пpoцecce вызoвoв tgetnum, tgetflag и tgetstr. Tgetent вoзвpaщaeт -1 в cлyчae, ecли пpoизoшлa oшибкa пpи oткpытии фaйлa termcap, вoзвpaщaeт 0, ecли нeт oпиcaния дaннoгo тepминaлa, и вoзвpaщaeт 1, ecли вce нopмaльнo.

* Переменная окружения TERM содержит [идентификатор возможностей текстового окна](https://brlcad.org/docs/doxygen-r64112/dd/dfa/cursor_8c.xhtml). Вы можете получить подробный список этих возможностей, используя команду «infocmp», используя «man 5 terminfo» в качестве референса.
При создании текста со встроенными цветовыми директивами msgcat просматривает переменную TERM. Текстовые окна сегодня обычно поддерживают не менее 8 цветов. Однако часто текстовое окно поддерживает 16 или более цветов, даже если для переменной TERM задан идентификатор, обозначающий только 8 поддерживаемых цветов. В этих случаях может быть целесообразно установить для переменной TERM другое значение:\
`xterm`\
xterm в большинстве случаев построен с поддержкой 16 цветов. Он также может быть построен с поддержкой 88 или 256 цветов (но не обоих). В большинстве случаев (в среде macOS) по умолчанию используется xterm, и, поскольку будет использоваться конфигурация xterm, можно установить env = "xterm".
```
char *env = getenv("TERM");
if (env == NULL)
	env = "xterm";
tgetent(NULL, env);					// использование настроек xterm
char *cm = tgetstr("cm", NULL);		// для движения курсора(cursor motion)
char *ce = tgetstr("ce", NULL);		// для стирания от текущей позиции курсора до конца строки(cursor erase)
```
### Переместить курсор в указанную позицию
В библиотеке `termcap` вы можете получать команды, необходимые для выполнения действия, с помощью функции tputs() и функции tgoto(). Переместить курсор в позицию (5, 5) можно следующим образом:
```
int putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

int main(void)
{
	tgetent(NULL, "xterm");
	char *cm = tgetstr("cm", NULL);
	tputs(tgoto(cm, 5, 5), 1, putchar_tc);
}
```
Через tgoto(cm, 5, 5) команда на перемещение в позицию (5, 5) (cm — движение курсора) передается на tputs и выполняется. Верхний левый угол окна терминала (0, 0).
В случае ce - команда очистки строки от курсора, вы можете использовать ее в виде tputs(ce, 1, putchar_tc) без tgoto.

### Принимать ввод с клавиатуры и перемещать курсор([примеры не мои, не спрашивайте плиз](https://hyeonski.tistory.com/6?category=471028))
```
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235

int	nbr_length(int n)
{
	int	i = 0;

	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cursor_position(int *col, int *rows)
{
	int		a = 0;
	int		i = 1;
	char	buf[255];
	int		ret;
	int		temp;

	write(0, "\033[6n", 4);  //ищём местоположение курсора
	ret = read(0, buf, 254); //считываем
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*rows = atoi(&buf[i]) - 1;
			else
			{
				temp = atoi(&buf[i]);
				*col = temp - 1;
			}
			a++;
			i += nbr_length(temp) - 1;
		}
		i++;
	}
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(int *col, int *row, char *cm)
{
	if (*col == 0)
		return ;
	--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	move_cursor_right(int *col, int *row, char *cm)
{
	++(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	delete_end(int *col, int *row, char *cm, char *ce)
{
	if (*col != 0)
		--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
}

int		main(void)
{
	/* настройки term */
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	/* инициализация термкапа */
	tgetent(NULL, "xterm");
	char *cm = tgetstr("cm", NULL); //для движения курсора(cursor motion)
	char *ce = tgetstr("ce", NULL); //для стирания от текущей позиции курсора до начала

	int c = 0;
	int row;
	int col;

	while (read(0, &c, sizeof(c)) > 0)
	{
		get_cursor_position(&col, &row);
		if (c == LEFT_ARROW)
			move_cursor_left(&col, &row, cm);
		else if (c == RIGHT_ARROW)
			move_cursor_right(&col, &row, cm);
		else if (c == BACKSPACE)
			delete_end(&col, &row, cm, ce);
		else
		{
			col++;
			write(0, &c, 1);
		}
		c = 0;
	}
}

```
Давайте сначала посмотрим на функцию get_cursor_position(). Выводит строку "\033[6n" в стандартный ввод и считывает ее снова, которая является escape-символом ANSI и выводит текущую позицию курсора в стандартный ввод. Он выводится в виде [row;colR, например [1;3R], и текущая позиция курсора может быть сохранена путем анализа выходной позиции. В это время выходная позиция курсора на единицу больше, чем координаты фактически используемого курсора. Если координата (0, 0), она выводится как [1; 1R], поэтому вам нужно сохранить значение минус 1 при парсинге. Здесь положение перемещаемого курсора может быть известно при вычислении на основе сохраненного положения курсора. Если это не двойная стрелка или пробел, он обрабатывается как обычный символ и выводится в STDIN. Backspace пишется таким образом, что столбец уменьшается на единицу, а символ после него убирается.

#### * tgetflag `int  tgetflag (char  * i)`
Tgetflag вoзвpaщaeт 1 в cлyчae, ecли yкaзaннaя xapaктepиcтикa id cyщecтвyeт для дaннoгo тepминaлa, и 0 в пpoтивнoм cлyчae.

#### * tcgetattr `int tcgetattr(int fd, struct termios *t)`
В качестве аргумента получает файловый дескриптор объекта, с которым нужно работать. Поскольку значение атрибута записывается с помощью указателя, возвращаемое значение указывает на результат выполнения функции tcgetattr. Если выполнение функции успешно завершено, возвращается 0, иначе возвращается -1. Этот вызов записывает текущие значения переменных интерфейса терминала в структуру, на которую указывает параметр termios_p. Если впоследствии эти значения будут изменены, вы сможете перенастроить интерфейс терминала с помощью функции tcsetattr.
#### * tcsetattr `int tcsetattr(int fd, int action, const struct termios *t)`
Есть три варианта:\
`TCSANOW` — изменяет значения сразу; \
`TSCADRAIN` — изменяет значения, когда текущий вывод завершен; \
`TCSAFLUSH` — изменяет значения, когда текущий вывод завершен, но отбрасывает любой ввод, доступный в текущий момент и все еще не возвращенный вызовом read.\
`TCSANOW` означает немедленное изменение значения структуры termios. `TSCADRAIN` и `TCSAFLUSH` означают изменение после выполнения всех операций записи в файловый дескриптор цели. При использовании `TCSASOFT` значения `c_cflag`, `c_ispeed` и `c_ospeed` в структуре termios игнорируются.\

#### * tgoto `char *tgoto(const char *cap, int col, int row)`
`col` означает положение вертикального столбца терминала, а `row` означает положение горизонтального ряда терминала. `cap` означает Capability, и используется [управляющая последовательность](https://ru.wikipedia.org/wiki/%D0%A3%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B0%D1%8F_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D1%8C) для cm, которая обычно представляет собой движение курсора. Конечно, вы можете использовать [другие управляющие последовательности](https://en.wikipedia.org/wiki/Escape_sequences_in_C), но лучше избегать других управляющие последовательности для подпрограммы с именем tgoto, потому что безопаснее всего использовать последовательность для движения курсора.
Подпрограмма tgoto возвращает последовательность движения курсора с учетом `col` и `row` . Поэтому, если вы используете эту строку в качестве аргумента для tputs, вы можете увидеть, что курсор на терминале перемещается. Если рутинная операция не удалась, возвращается NULL.
#### * tputs `int tputs(const char *str, int affcnt, int (*putc)(int))`
`tputs` — это подпрограмма, которая выводит результат вывода терминала для управляющей последовательности, а аргумент str — это управляющая последовательность, полученная с помощью `tgetstr` или `tgoto`. `affcnt` означает количество строк, на которые будет воздействовать `tputs`, и обычно устанавливается равным 1, если это не влияет на несколько строк. Аргумент putc является указателем на функцию, которая получает аргумент типа int и возвращает тип int.
Если подпрограмма с именем `tputs` выполняется без проблем, она возвращает 0, иначе возвращается -1.
#### * ioctl `int ioctl(int fd, unsigned long request, ...)`
Функция ioctl() изменяет базовые параметры устройства, представленного в виде специального файла. В частности, через запросы ioctl() можно управлять многими оперативными характеристиками специальных символьных файлов (например, терминалов). В качестве аргумента fd должен быть указан открытый файловый дескриптор.
Второй аргумент является кодом запроса, значение которого зависит от устройства. Третий аргумент является нетипизированным указателем на память. Обычно, это char *argp (было до тех пор, пока в C не появился vvoid *) и далее он будет называться именно так.

В значении request функции ioctl() кодируется информация является ли параметр входным или выходным и размер аргумента argp в байтах. Макросы и определения, используемые при указании в ioctl() запросах request, определены в файле <sys/ioctl.h>.В это время ввод fd в качестве аргумента ioctl становится дескриптором файла, полученным через open, но иногда могут возникать неожиданные результаты как побочный эффект функции. Соответственно, рекомендуется также использовать флаг O_NONBLOCK при открытии.
Аргумент запроса — это код, предоставляемый устройством для отправки устройству, соответствующему fd, а последний аргумент — это указатель, ссылающийся на определенное пространство памяти. Причина, по которой переменный аргумент используется, несмотря на то, что последний аргумент является типом указателя, состоит в том, чтобы не указывать тип указателя в прототипе функции. В общем, тип char* используется для переменной аргумента последнего аргумента при вызове функции.
```
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int	main(void)
{
	struct winsize	size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return (1);
	printf("Terminal Row Size:\t%d\n",size.ws_row);
	printf("Terminal Col Size:\t%d\n",size.ws_col);
	return (0);
}
```
![Screenshot from 2022-01-18 17-39-21](https://user-images.githubusercontent.com/84707645/149958388-0caf679f-c5d2-4849-881a-cedbcc872157.png) \
А если уменьшить окно VsCode, то магия, Карл \
![Screenshot from 2022-01-18 17-41-39](https://user-images.githubusercontent.com/84707645/149958725-fd0d4005-eee0-494a-9701-7ec75936b8ee.png)

#### * wait3 `pid_t wait3(int *status, int options, struct rusage *rusage)`

Функция wait3 является устаревшей(после появляется функция waitpid). Сама функция аналогична функции `waitpid`.
Вызов `wait3(status, options, rusage)` эквивалентен вызову `waitpid(-1, status, options)`. Причина использования функции wait3 вместо функции waitpid заключается в структуре, называемой `rusage.` Аргумент rusage является аббревиатурой Resource Usage и представляет собой структуру, указывающую объем использования ресурсов. Системные вызовы wait3() и wait4() полезны, если вы интересуетесь ресурсами, использованными порожденным процессом. Если значение структуры rusage для wait3 не равно NULL, в rusage записывается различная информация о ресурсе дочернего процесса, пока выполняется функция wait3.
Причина того, что функция wait3 устарела, заключается в стандартизации. Функция wait3 соответствует системному вызову системы BSD, и было рекомендовано использовать waitpid, так как он стандартизирован POSIX. В это время, если вы внимательно посмотрите на функцию waitpid, вы увидите, что wait3 заменена на waitpid, так что можно использовать options, но невозможно получить rusage. Это связано с тем, что waitpid больше не использует rusage для определения цели функции. По этой причине rusage можно получить с помощью функции getrusage.
Возвращаемое значение и обработка ошибок функции wait3 такие же, как у wait и waitpid. Возвращаемое значение типа pid_t означает pid дочернего процесса, и если есть проблема в выполнении функции или дочерний процесс завершается по сигналу, возвращается -1.

#### * wait4 `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage)`

Функция wait4, как и функция wait3, является устаревшей функцией( появились waitpid или waitid). Сама функция такая же, как и у функция waitpid, а отличие от функции wait3 в том, что работу функции можно указать в любом дочернем процессе.
Вызов wait4(pid, status, options, rusage) эквивалентен вызову waitpid(pid, status, options).
Рекомендуется прочитать приведенную выше функцию wait3, потому что функция wait4 работает так же, как и функция wait3, за исключением того, что она может указывать дочерний процесс.

#### * getcwd `char *getcwd(char *buf, size_t size)`

getcwd — это функция, которая позволяет получить абсолютный путь, по которому запущена программа, вызвавшая getcwd, в виде строки. Абсолютный путь записывается в аргумент типа char *с именем buf, а size означает размер buf. Так как строка, записанная в buf, заканчивается нулевым символом '\0', следует иметь в виду, что size — это размер, включающий нулевой символ. Если длина строки абсолютного пути для записи в buf превышает размер с учетом нулевого символа, возвращается NULL. Если запись абсолютного пути прошла успешно, возвращается адрес buf.
Особенность getcwd заключается в том, что если в качестве аргумента buf вводится NULL, адрес пространства возвращается после получения внутреннего динамического распределения с размером size. Если невозможно записать абсолютный путь, потому что он динамически выделяется с размером, равным размеру, он динамически выделяется с размером, достаточным для записи абсолютного пути. В этом случае пользователь должен напрямую вызвать free для динамически выделенного пространства. Если есть проблема с выполнением функции, возвращается NULL.

```
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (1);
	printf("%s\n", path);
	free(path);
	path = NULL;
	return (0);
}
```
![Screenshot from 2022-01-18 18-01-36](https://user-images.githubusercontent.com/84707645/149962346-f12e4102-4122-40cd-9ac6-fcb72df168f8.png)

#### * chdir `int chdir(const char *path)`

Функция изменяет текущий рабочий каталог вызывающего процесса в каталог, указанный в пути. Если изменение пути прошло успешно, возвращается 0, а при возникновении ошибки возвращается -1.

```
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (1);
	printf("Before:\t%s\n", path);
	free(path);
	path = NULL;
	if (chdir("../") == -1)
		return (1);
	path = getcwd(NULL, 0);
	if (!path)
		return (1);
	printf("After:\t%s\n", path);
	free(path);
	path = NULL;
	return (0) ;
}
```
![Screenshot from 2022-01-18 18-19-53](https://user-images.githubusercontent.com/84707645/149966290-58c3ae77-59f8-4010-906d-f2065012e487.png)

#### * isatty `int  isatty (int fd) `
Сообщает, [подключен ли](https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-isatty-test-if-descriptor-represents-terminal) дескриптор файла к терминалу или нет. Параметр является индексом в таблице дескрипторов файлов стандартной библиотеки ввода-вывода. Индексы 0, 1 и 2 зарезервированы для stdin , stdout и stderr . Все остальные индексы относятся к дескрипторам файлов, которые могут/были открыты вами.
```
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	censor(int fd, const char *s)
{
	if (isatty(fd))
	{
		if (s)
			printf("%s is referring to a terminal\n", s);
		else
			printf("File Descriptor %d is referring to a terminal\n", fd);
	}
	else
	{
		if (s)
			printf("%s is not referring to a terminal\n", s);
		else
			printf("File Descriptor %d is not referring to a terminal\n", fd);
	}
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	if (fd < 0)
		return (1);
	censor(STDIN_FILENO, "STDIN");
	censor(STDOUT_FILENO, "STDOUT");
	censor(STDERR_FILENO, "STDERR");
	censor(fd, NULL);
	censor(1, NULL);
	close(fd);
	return (0);
}
```

#### * ttyname `char *ttyname(int fd)`
Если дескриптор файла с именем fd, полученный в качестве аргумента, относится к терминалу, путь к терминалу возвращается в виде строки, оканчивающейся нулевым символом с именем '\0' . Если есть проблема с выполнением функции или fd не ссылается на терминал, возвращается NULL. Поскольку возвращаемая строка размещается внутри в статической форме, ее значение может быть перезаписано последовательными вызовами ttyname. Кроме того, поскольку он выделен в статической форме, нет необходимости делать free() отдельнo.
```
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	censor(int fd, const char *s)
{
	if (isatty(fd))
	{
		if (s)
			printf("%s is referring to a terminal\n", s);
		else
			printf("File Descriptor %d is referring to a terminal\n", fd);
	}
	else
	{
		if (s)
			printf("%s is not referring to a terminal\n", s);
		else
			printf("File Descriptor %d is not referring to a terminal\n", fd);
	}
	printf("TTYNAME:\t%s\n", ttyname(fd));
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	if (fd < 0)
		return (1);
	censor(STDIN_FILENO, "STDIN");
	censor(STDOUT_FILENO, "STDOUT");
	censor(STDERR_FILENO, "STDERR");
	censor(fd, NULL);
	censor(42, NULL);
	close(fd);
	return (0);
}
```

#### * ttyslot `int ttyslot(void)`
Возвращает индекс терминала, на который ссылается программа, вызвавшая ttyslot. Если возникает проблема с выполнением функции, возвращается 0 или -1 в зависимости от используемой системы. Возвращаемое значение используется в качестве индекса записи в БД для терминала. Обратите внимание, что функция ttyslot является устаревшей функцией.
```
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	censor(int fd, const char *s)
{
	if (isatty(fd))
	{
		if (s)
			printf("%s is referring to a terminal\n", s);
		else
			printf("File Descriptor %d is referring to a terminal\n", fd);
	}
	else
	{
		if (s)
			printf("%s is not referring to a terminal\n", s);
		else
			printf("File Descriptor %d is not referring to a terminal\n", fd);
	}
	printf("TTYNAME:\t%s\n", ttyname(fd));
}

int	main(void)
{
	int	fd;

	printf("TTYSLOT:\t%d\n", ttyslot());
	fd = open("test", O_RDONLY);
	if (fd < 0)
		return (1);
	censor(STDIN_FILENO, "STDIN");
	censor(STDOUT_FILENO, "STDOUT");
	censor(STDERR_FILENO, "STDERR");
	censor(fd, NULL);
	censor(42, NULL);
	close(fd);
	return (0);
}
```

#### * getenv `char *getenv(const char *name)`
Возвращает строку для значения переменной среды, соответствующей name. Если значение, соответствующее переменной среды, не найдено или возникла проблема с выполнением функции, возвращается NULL. Следует иметь в виду, что значения, на которые ссылается getenv, не должны освобождаться, потому что они внутренне распределены как статические типы.
```
#include <stdio.h>

int	main(void)
{
	char	*term;

	term = getenv("TERM");
	if (!term)
		return (1);
	printf("Term Type is %s\n", term);
	return (0);
}
```
![Screenshot from 2022-01-18 18-44-21](https://user-images.githubusercontent.com/84707645/149969934-8705080e-07c3-4e4f-b74d-8f17f5f40363.png)

#### * signal `typedef void (*sighandler_t)(int)`
`sighandler_t signal(int signum, sighandler_t handler)` \
[Какая-то боль](https://ru.wikipedia.org/wiki/%D0%A1%D0%B8%D0%B3%D0%BD%D0%B0%D0%BB_(Unix))
```
#include <stdbool.h>
#include <unistd.h>

void	handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "write From Signal\n", 18);
}

int	main(void)
{
	signal(SIGINT, handler);
	while(true)
		;
	return (0 ) ;
}
```
![Screenshot from 2022-01-18 18-52-33](https://user-images.githubusercontent.com/84707645/149971462-50e8cde1-257d-44a8-80f1-a29bd0c3aff7.png)

#### * opendir `DIR *opendir(const char *name)`
Возвращает указатель типа (DIR * ), ссылающийся на поток каталога с именем, соответствующим name. Если нет каталога, соответствующего имени, или есть проблема в выполнении функции, возвращаемое значение указателя типа DIR * равно NULL.
[Для работы с директориями](https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html) необходимо определить переменную типа DIR (по смыслу она похожа на тип FILE). То есть структура DIR в основном используется как средство для манипулирования каталогами.
DIR*, тип указателя структуры, называемой DIR, часто называют потоком каталогов, и он используется в формате, аналогичном FILE*, файловому потоку для обычных операций с файлами. Поток в потоке каталогов и файловый поток относятся к потоку данных абстрактного промежуточного носителя для облегчения выполнения конкретной задачи. Чтобы понять это, нам нужно понять происхождение потока.
Тип DIR , определенный в заголовке <dirent.h> , представляет поток каталога, который представляет собой упорядоченную последовательность всех записей каталога в определенном каталоге. Записи каталога представляют файлы; файлы могут быть удалены из каталога или добавлены в каталог асинхронно с операцией readdir().
Для типа указателя структуры dirent, полученной через функцию readdir, место в памяти, на которое ссылается указатель, выделяется статически, поэтому нет необходимости вызывать функцию free отдельно.

[Файлы устройств размещаются в каталоге](http://gentoo.theserverside.ru/book/secrets_of_dev.html) /dev или в его подкаталогах.

Узнать информацию о файле устройства можно с помощью команд file и ls.

/dev (от англ. devices — устройства) — каталог в системах типа UNIX, содержащий так называемые специальные файлы — интерфейсы работы с драйверами ядра. Как правило (хотя и не всегда), /dev является обычным каталогом в корневой файловой системе, куда можно (но не нужно) помещать и обычные файлы. Доступ на запись к /dev (то есть право добавлять и перемещать специальные файлы) имеет только суперпользователь. Сами «специальные файлы» могут быть как доступны простому пользователю (терминал, псевдоустройства), так и недоступны (жёсткие диски).
```
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


void listFiles(const char *path);

int main()
{
    // Путь до директории
    char path[100];

    // Путь, который прописал нам пользователь
    printf("Enter path to list files: ");
    scanf("%s", path);

    listFiles(path);

    return 0;
}


// Список всех файлов в заданной директории

void listFiles(const char *path)
{
    struct dirent *dp;
    DIR *dir = opendir(path); //DIR * в качестве имени каталога, из которого нужно прочитать список

    // Если не получается открыть поток
    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL) //Читает имена файлов или каталогов одно за другим по порядку с начала каталога
        printf("%s\n", dp->d_name);

    // Закрываем поток
    closedir(dir);
}
```
![Screenshot from 2022-01-19 14-29-12](https://user-images.githubusercontent.com/84707645/150121842-c315298c-8d41-4f96-84d3-ecef1404803e.png)

```
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>

void	classify(struct dirent *ent)
{
	printf("%s\t", ent->d_name);
	if (ent->d_type == DT_BLK)
		printf("Block Device\n");
	else if (ent->d_type == DT_CHR)
		printf("Character Device\n");
	else if (ent->d_type == DT_DIR)
		printf("Directory\n");
	else if (ent->d_type == DT_LNK)
		printf("Symbolic Link\n");
	else if (ent->d_type == DT_REG)
		printf("Regular File\n");
	else if (ent->d_type == DT_SOCK)
		printf("Unix Domain Socket\n");
	else
		printf("Unknown Type File\n");
}

int		main(void)
{
	int				temp;
	DIR				*dirp;
	struct dirent	*file;

	dirp = opendir("test_dir");
	if (!dirp)
	{
		printf("error\n");
		return (1);
	}
	while (true)
	{
		temp = errno;
		file = readdir(dirp);
		if (!file && temp != errno)
		{
			printf("error\n");
			break ;
		}
		if (!file)
			break ;
		classify(file);
	}
	closedir(dirp);
	return (0);
}
```
## dup & dup2
command > file  : перезапишите стандартный вывод в файл или создайте новый файл, если он не существует. dup2(fd, 1)\
command < file  : передать данные файла на стандартный ввод команды. dup2(fd, 0) \
command >> file : добавьте стандартный вывод в файл после символа новой строки или создайте новый файл, если он не существует.\
dup2(in_fd, 0). Замените стандартный ввод файлом, на который указывает in_fd\
dup2(out_fd, 1). Замените стандартный вывод файлом, на который указывает out_fd => С тех пор все результаты стандартного вывода записываются в файл, на который указывает. \
В зависимости от символа перенаправления файл всегда появляется справа, а команда — слева. \(команды можно не указывать)
Например, сами определим макросы так, что
* STDIN это fd[0]
* STDOUT это fd[1]
* STDERR это fd[2]

Тогда
* Стандартный ввод — это дескриптор файла, который ваш процесс считывает, чтобы получить от вас информацию.

* Стандартный вывод — ваш процесс записывает обычный вывод в этот дескриптор файла.

* Стандартная ошибка — ваш процесс записывает диагностические данные в этот дескриптор файла.
Например, нам нужно заменить id с fd2 на fd1, тогда при исполнении int dup2(fd, stdout) выходные данные направляются в fd. Если мы юзаем dup2, то мы можем создать программу, в которой родительский процесс передаёт строку дочернему процессу в качестве стандартного ввода. Бадумц, надо посмотреть пример!
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd1 = open("./password", O_CREAT | O_WRONLY, 0755);

    printf( "fd1 is :: %d\n", fd1);
    write(fd1, "Tony?\n", strlen("Tony?\n"));

    int fd2 = dup(fd1);

    printf( "fd2 is :: %d\n" ,fd2);
    write(fd2, "Ezekiel?\n", strlen("Ezekiel?\n"));
    return 0;
}
```
<img width="408" alt="Screen Shot 2022-01-21 at 2 58 37 PM" src="https://user-images.githubusercontent.com/84707645/150524072-82cd71c0-6f3e-4ef8-b53c-bb88835ab2a5.png">

fd1 и fd2 имеют разные номера: 3 и 4 соответственно, но в результате того, что мы writом записали в тот же файл(файл password) строку, то мы сделали копию. Получается, что когда мы закроем fd1, то fd2 будет ещё жить. Значит fd открыл ещё один fd, после вызова dup. fd1 и fd2 — совершенно разные файловые дескрипторы, которые указывают на один и тот же файл.

Тогда посмотрим на dup2, dup2 можно рассматривать как более продвинутый системный вызов, допустим. Функции dup и dup2 используются совершенно по-разному. \
Разница между dup и dup2 заключается в том, что dup назначает наименьший доступный номер файлового дескриптора, а dup2 позволяет вам выбрать номер файлового дескриптора, который будет назначен.
Например,
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("./password" , O_CREAT | O_WRONLY, 0755);
	dup2(fd, 1); //STDOUT это 1 у нас

	char buffer[20] = "welcome!\n";
   	printf( "%s", buffer);
	fflush(stdout); //потому что write быстрее printf, мы очистим буфер
	write(1, buffer, strlen(buffer));
	write(fd, buffer, strlen(buffer));
	close(fd);
    return 0;
}

```
<img width="404" alt="Screen Shot 2022-01-21 at 3 22 55 PM" src="https://user-images.githubusercontent.com/84707645/150526439-7b92bb78-2ac0-474a-86ea-b37c765f3f92.png">

Исходя из примера что произошло:

После создания файлового дескриптора fd мы вызвали функцию dup2(fd, 1), весь вывод записывается в fd. Т.е. мы изменили fd на stdout(1), используя dup2.
Ладно, не очень понятно, что произошло.

## PIPES
Пайпы дают возможность передавать данные от одного процесса к другому(однонаправленный поток данных). Это позволяет нескольким командам работать вместе для достижения одной цели. Каждая команда пайплайна выполняется в независимом процессе и каждая инструкция выполняется в независимом пространстве памяти. Способ взаимодействия каждого процесса друг с другом предоставляет вызов функции pipe().
Создаётся массив, в котором хранятся два целочисленных значения и вызов функции возвращает два значения файлового дескриптора файлов(обычно это fd с наименьшим доступным номером).
Если думать о пайпе как о реальной трубе, которая соединяет две других, то становится более-менее понятно: единственный способ, которым вода может попать в пространство следующей трубы это соединить две трубы третьей трубой.

<img width="604" alt="Screen Shot 2022-01-21 at 4 39 52 PM" src="https://user-images.githubusercontent.com/84707645/150536894-8f3798bb-4b00-4aae-a86c-8f40e1d59524.png">

<img width="286" alt="Screen Shot 2022-01-21 at 4 41 08 PM" src="https://user-images.githubusercontent.com/84707645/150536879-396a0329-6ca9-4dde-b061-cfe7151cf4b2.png">

Что происходит: команда 'sort' ждёт пока пользователь(STDIN(file descriptor 0)) выполнит ввод. Затем входные строки сортируются в алфавитном порядке, а отсортированный результат передаётся через STDOUT.

Прежде чем продолжить, следует помнить один важный момент: у каждого процесса есть своя собственная [таблица файловых дескрипторов](https://en.wikipedia.org/wiki/File_descriptor). Поскольку каждая команда в пайплайне выполняется в своем собственном независимом процессе, каждая команда имеет свою собственную версию файлового дескриптора, а также свой собственный стандартный ввод, стандартный вывод и стандартный вывод ошибки. Это означает, что на диаграмме выше крайний левый элемент принадлежит процессу, выполняющему команду, поэтому он находится в другой таблице файловых дескрипторов, чем тот, что находится в правом конце диаграммы, и принадлежит процессу выполнение команды. Но поскольку потоки настроены на отправку данных через границы процесса, если данные хорошо проходят через конвейер, они в конечном итоге перейдут к конечному процессу. Команда сортировки имеет на выходе отсортированный список строк, и для того, чтобы в результате доставить выходные данные следующему процессу (grep), выходные данные должны быть доставлены в созданный канал.
Приведенные выше диаграммы — это модели, в которых данные передаются слева направо. Дескриптор файла установлен в массиве, так что данные, записываемые в 4, считываются из 3. Но вы можете удивиться, почему 4 идет слева, а 3 — справа.
Данные передаются от первого процесса (sort) в конвейер, конвейер ожидает, пока все данные не будут доставлены, и когда все данные будут доставлены, конвейер отправляет данные следующему процессу ( ). И, наконец, процесс, выполняющий команду, получивший данные из канала grep, выводит строку, содержащую «ea» среди входных данных, на стандартный вывод и отправляет ее на терминал.
```
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fds[2]; //массив, хранящий два файловых дескриптора
	pipe(fds); //множим файловые дескрипторы
	pid_t pid = fork();//создаем дочерний процесс, который копия родителя

	if (pid == 0)//если pid == 0, то это дочерний процесс
	{
		dup2(fds[0], STDIN_FILENO); //fds[0](тот конец пайпа, который read) делится инфой с фд 0
		close(fds[0]);//этот фд больше не нужен в ребенке
		close(fds[1]);//этот фд не используется в ребенке
		char *argv[] = {(char *)"sort", NULL};
		if (execvp(argv[0], argv) < 0) //запустили команду 'sort'
			exit(0);
	}
	//если мы дошли до сюда, значит мы в родительском процессе
	close(fds[0]);//этот фд не используется в родителе
	const char *words[] = {"pear", "peach", "apple"};
	//записать ввод в доступный для записи дескриптор файла, чтобы его можно было прочитать из дочернего
	size_t numwords = sizeof(words)/sizeof(words[0]);
	for (size_t i = 0; i < numwords; i++)
		dprintf(fds[1], "%s\n", words[i]);
	//отправить EOF, чтобы дочерний элемент мог продолжить (дочерний блокируется до тех пор, пока не будет обработан весь ввод)
	close(fds[1]);
	int status;
	pid_t wpid = waitpid(pid, &status, 0); //эжём ребенка прежде чем выйти
	return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}
```
[Вы можете выполнить команду в родительском процессе, не создавая дочерний процесс].(https://architectophile.tistory.com/9)
Но если вы думаете, что пишете код, который может обрабатывать как одну команду, так и несколько команд в пайплайне, в этом случае всегда следите за тем, чтобы разные дочерние процессы выполняли разные команды. В этом примере входные данные dprintf() напрямую выводятся в файловый дескриптор с помощью функции, чтобы показать случай, когда данные передаются от родительского процесса к дочернему процессу. с помощью пайпа.

1. Сначала создается один массив для хранения двух файловых дескрипторов родительского процесса.
2. После вызова pipe() массив заполняется двумя конкатенированными файловыми дескрипторами. Первый элемент массива используется для чтения из дочернего процесса, а второй используется для записи из инпута в аутпут.
3. fork() вызывается для дочернего процесса, которая дубоирует дескрипторы файлов в память
4. Теперь мы проверяем, является ли запущенный в данный момент идентификатор процесса дочерним процессом \
В СЛУЧАЕ РЕБЕНКА
5. Функция dup2() соединяет собственный stdin с пайпом с того конца, который на чтение. Что надо знать так это то, что когда работает функция dup2(), файловый дескриптор второго параметра закрывается первым. Таким образом, в приведенном выше примере stdin (стандартный ввод, открытый по умолчанию) сначала закрывается, а ссылка на файл клавиатуры по умолчанию удаляется. После этого дочерний процесс дочернего процесса получает данные с уже не stdin клавиатуры , а от fds[0].
6. Теперь информация из stdin дочернего процесса готова к чтению, а созданный pipe() файлового дескриптора больше не нужен, поэтому закройте файловый дескриптор:close(fds[0]); close(fds[1]);
7. Теперь дочерний процесс execvp() вызывает функцию для выполнения команды и ждет, пока sort все данные родительского процесса не будут записаны в читаемый конец канала.
8. Когда все данные от родительского процесса передаются дочернему процессу через входной конец канала, команда sort сортирует данные, выводит результат на дисплей терминала через стандартный вывод, и после возврата вызова execvp() дочерний процесс процесс автоматически закрывает файловые дескрипторы 0, 1 и 2 по умолчанию.
<img width="636" alt="1" src="https://user-images.githubusercontent.com/84707645/150566169-48c5abd7-3af2-4959-b4cc-f6d39e644571.png">
<img width="636" alt="2" src="https://user-images.githubusercontent.com/84707645/150566194-cb9e13f7-5f90-4eae-87cc-388a38de6350.png">
<img width="636" alt="3" src="https://user-images.githubusercontent.com/84707645/150566209-bfea3887-6c95-4470-a263-48328d2b62f8.png">
<img width="636" alt="4" src="https://user-images.githubusercontent.com/84707645/150566230-4673c80e-55d2-4f7e-b3bd-b5c8ee713b0a.png">
<img width="636" alt="5" src="https://user-images.githubusercontent.com/84707645/150566237-b506c22c-ae2a-44e0-8c93-830796f01aee.png">
<img width="636" alt="6" src="https://user-images.githubusercontent.com/84707645/150566243-596d0928-0aa7-453b-887f-043ad0ea9e86.png">
<img width="636" alt="7" src="https://user-images.githubusercontent.com/84707645/150566259-00e8679d-b5ab-463b-a525-9680499250ea.png">
<img width="636" alt="8" src="https://user-images.githubusercontent.com/84707645/150566267-b0f89784-1e57-4bf0-87eb-9e1506c823ef.png">
<img width="636" alt="9" src="https://user-images.githubusercontent.com/84707645/150566281-754d251a-e4ee-4999-bdd4-228ae946dea2.png">
<img width="636" alt="10" src="https://user-images.githubusercontent.com/84707645/150566291-014d688d-e24a-4b5b-91eb-8e48480044fc.png">

##  Приоритет выполнения в дереве
```
echo a && echo b
```
Для каждого из операторов && правая команда выполняется, только если левая команда возвращает 0 (true).
```
echo a || echo b
```
Для каждого оператора || правая команда выполняется только в том случае, если левая команда возвращает 1 (false).
```
true || echo aaa && echo bbb
```
Выводом будет только `bbb`
Эти два оператора имеют наивысший приоритет в списке и они равны между собой по приоритету, такие дела. При отсутствии группирующий структур в первую очередь выполняются крайние левые операции, потому что операторы с одинаковым приоритетом являются левоассоциативными. Из примера самая левая операция (||) выполняется первой. 
Т.е. сначала идёт оценка. `true || echo aaa` и, очевидно, true есть true, т.е. мы идём дальше без оценки `echo aaa`, потом выполняем только часть `echo bbb`
Тут всё. Идём дальше:
```
a || b && c && d || e || f && g
```
1. Сначала разбиваем на 2 с последним найденным оператором с высоким приоритетом
```
[a || b && c && d || e || f] && [g]
```
2. Разделяем левую часть на 3 на основе двух последних аналогичных высокоприоритетных операторов.
```
[a || b && c && d] || [e] || [f]
```
3. Разделяем крайнюю левую часть на 3 на основе двух последних аналогичных высокоприоритетных операторов
```
[a || b] && [c] && [d]
```
```
				   [&&]
				  /   \
				 /     \
			       [||]    [g]
			      /	  \
			    /	    \
			  /	      \
     	                [&&]          [||]
    		       /     \        /   \
     		     /         \     /     \
		   [||]        [&&][e]     [f]
		  /    \        /  \
		 /      \      /    \
	       [a] 	[b] [c]     [d]	
			 
```
Оператор с наивысшим приоритетом после И и ИЛИ — это ПАЙП.
РЕДИРЕКТЫ после ПАЙПА. Три разных перенаправления могут не соблюдать какой-либо порядок приоритета между ними, мы можем решить, равны они или различны, это не имеет значения. Их можно выполнять в любом порядке.
```
ls >> file1 | rev | cut -c1-10
```
```
                  [ | ]
                 /     \
	        /       \
	 [>> file1]      [|]
	 	\	 /  \
		[ls]  [rev] [cut -c1-10]
```
