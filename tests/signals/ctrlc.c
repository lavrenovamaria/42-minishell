#include <termios.h>
#include "minishell.h"

void rl_replace_line (const char *text, int clear_undo)
{
	return ;
}

void sig_handler(int signal)
{
	if (signal == SIGINT)
	{
	    printf("bash-3.2$ \n");
	}
	if (rl_on_new_line() == -1)
	    exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void setting_signal()
{
    signal(SIGINT, sig_handler); // CTRL + C
    signal(SIGQUIT, SIG_IGN);    // CTRL + /
                                 // signal(SIGTERM, sig_handler);
}
int main(void)
{
	struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    setting_signal();
}
