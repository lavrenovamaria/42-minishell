#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft/libft.h"

# define FLAG_PIPE_OUT		0b000001
# define FLAG_STDOUT		0b000010
# define FLAG_PIPE_IN		0b000100
# define FLAG_STDIN			0b001000
# define FLAG_REDIRECT_1	0b010000
# define FLAG_REDIRECT_2	0b100000

typedef struct		s_command
{
	char *command;
	char *args;
	int flags;
} t_command;

typedef struct		s_arguments
{
	int pipes_count;
	int commands_count;
} t_arguments;

// Service
t_list	*ft_lstindex(t_list *lst, int index);
