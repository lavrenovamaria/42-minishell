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
