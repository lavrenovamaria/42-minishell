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

void printList(t_list *n)
{
	//n = n->next;
	while (n != NULL)
	{
		printf("%s ", n->content);
		n = n->next;
	}
}

// void push(t_list *head, int val)
// {
// 	t_list *current = head;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = malloc(sizeof(t_list));
// 	current->next->content = val;
// 	current->next->next = NULL;
// }

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
	rl_redisplay();         // меняет
}

void setting_signal()
{
    signal(SIGINT, sig_handler); // CTRL + C
    signal(SIGQUIT, SIG_IGN);    // CTRL + /
                                 // signal(SIGTERM, sig_handler);
}

// int main(int argc, char **argv, char **envp)
// {
// 	char *str;
// 	struct termios term;

// 	setting_signal();
// 	while (1)
// 	{
// 		str = readline("bash-3.2$ ");
// 		if (!str)
// 		{
// 			printf("\033[1A");
// 			printf("\033[10C");
// 			printf(" exit\n");
// 			exit(-1);
// 		}
// 		else if (*str == '\0')
// 		{
// 			free(str);
// 		}
// 		else
// 		{
// 			add_history(str);
// 			printf("%s\n", str);
// 			free(str);
// 		}
// 	}
// 	return (0);
// }

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
			add_history(str);
			ft_lstadd_back(&head, ft_lstnew(str));
			printf("%s\n", str);
			free(str);
		}
	}
	return (0);
}
