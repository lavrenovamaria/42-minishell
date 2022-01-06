#include "minishell.h"

int main()
{
	void *command = malloc(sizeof(t_command));
	((t_command *)command)->command = "pwd";
	((t_command *)command)->args = NULL;
	((t_command *)command)->flags = 0;

	t_list *commands = ft_lstnew(command);
	while (commands)
	{
		t_command *comm;
		comm = (t_command *)commands->content;
		execlp(comm->command, comm->command, NULL);
		commands = commands->next;
	}
	return 0;
}
