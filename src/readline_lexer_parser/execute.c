#include "minishell.h"

int execute(t_list *commands)
{
	t_arguments args;
	args.pipes_count = 1;
	args.commands_count = 2;


	int fd[args.pipes_count][2];
	int count = 0;
	while (count < args.pipes_count)
		if (pipe(fd[count++]) == -1)
			return 1;


	int count_commands = 0;
	int count_pipes = 0;
	int pid;
	t_command *command;
	while (count_commands < args.commands_count)
	{
		pid = fork();
		if (pid < 0) {
			return 2;
		}

		if (pid == 0)
		{
			// Child
			command = (t_command *)ft_lstindex(commands, count_commands)->content;
			if (command)
			{
				if (command->flags & FLAG_PIPE_IN)
					dup2(fd[count_pipes][0], STDIN_FILENO);
				if (command->flags & FLAG_PIPE_OUT)
					dup2(fd[count_pipes][1], STDOUT_FILENO);
				while (count_pipes < args.pipes_count)
				{
					close(fd[count_pipes][0]);
					close(fd[count_pipes][1]);
					count_pipes++;
				}
				execlp(command->command, command->command, NULL);
			}
		}
		count_commands++;
		count_pipes = 0;
	}

	while (count_pipes < args.pipes_count)
	{
		close(fd[count_pipes][0]);
		close(fd[count_pipes][1]);
		count_pipes++;
	}

	wait(0);
	wait(0);
	return 0;
}

int main()
{
	void *command1 = malloc(sizeof(t_command));
	((t_command *)command1)->command = "ls";
	((t_command *)command1)->args = NULL;
	((t_command *)command1)->flags = 0;
	((t_command *)command1)->flags |= FLAG_PIPE_OUT;

	void *command2 = malloc(sizeof(t_command));
	((t_command *)command2)->command = "ls";
	((t_command *)command2)->args = NULL;
	((t_command *)command2)->flags = 0;
	((t_command *)command2)->flags |= FLAG_PIPE_IN;

	t_list *commands = ft_lstnew(command1);
	ft_lstadd_back(&commands, ft_lstnew(command2));

	execute(commands);
	return 0;
}
