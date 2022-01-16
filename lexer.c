//lexer breaks input into words and operators
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '	')
		return (1);
	return (0);
}

void printList(t_list *n)
{
	while (n != NULL)
	{
		printf("%s ", n->content);
		n = n->next;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!new)
		return ;
	if (*lst)
	{
		begin = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = begin;
	}
	else
		*lst = new;
}

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
	if (rl_on_new_line() == -1) // печать строки из readline
	    exit(1);
	rl_replace_line("", 1); // вывод строки, которую мы ввели в командной строку
	rl_redisplay();         // меняет то, что последнее было выведено
}

void setting_signal()
{
	signal(SIGINT, sig_handler); // CTRL + C
	signal(SIGQUIT, SIG_IGN);    // CTRL + /
}

int main(int argc, char **argv, char **envp)
{
	t_list *head = NULL;
	//head = (t_list*) malloc(sizeof(t_list));
	char *str;
	struct termios term;

	setting_signal();
	while (1)
	{
		str = readline("bash-3.2$ ");
		if (!str)
		{
			printf("\033[1A");
			printf("\033[10C");
			printf(" exit\n");
			printList(head);
			exit(-1);
		}
		else if (*str == '\0')
		{
			free(str);
		}
		else
		{
			while (ft_isspace(*str))
				str++;
			// while(*str)
			// {
			// 	if(*str == 34 || *str == 39)
			// 		str = ft_quotes(str);
			// 	else if(*str == '|' || *str == '&' || *str == '<' || *str == '>')
			// 		str = ft_pipes(str);
			// 	else if (*str == '(' || *str == ')')
			// 		str = ft_parentheses(str);
			// 	else
			// 		str = ft_args(str);
			// }
			add_history(str);//dima ya hz chto eto
			ft_lstadd_back(&head, ft_lstnew(str));
			parser(ft_split(str, ' '));
		}
	}
	return (0);
}
