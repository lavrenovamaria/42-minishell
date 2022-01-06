#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft/libft.h"

typedef struct		s_command
{
	char *command;
	char *args;
	int flags;
} t_command;
