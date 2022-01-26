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


typedef struct			s_tree
{
	void			*content;
	struct s_tree	*right;
	struct s_tree	*left;
	struct s_tree	*head;
	int				height;
}						t_tree;

t_tree	*create_node(void *content);
void	free_tree(t_tree *root);
void	rotateright(t_tree **root);
void	rotateleft(t_tree **root);
void	insert_right(t_tree** root, t_tree *node);
void	insert_left(t_tree** root, t_tree *node);
void	insert_up(t_tree** root, t_tree *node);

// Service
t_list	*ft_lstindex(t_list *lst, int index);
