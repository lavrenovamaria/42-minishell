#include "minishell.h"

t_list *parser(char **tokens)
{
	int token_ind;
	t_tree **head = NULL;
	t_tree **temp_head = malloc(sizeof(t_tree *));
	*temp_head = NULL;
	token_ind = 0;

	while (tokens[token_ind])
	{
		if (ft_strncmp(tokens[token_ind], "|", 5) == 0 || ft_strncmp(tokens[token_ind], ">", 5) == 0)
		{
			if (ft_strncmp(temp_head[0]->content, ">", 5) == 0)
			{
				insert_up(temp_head, create_node(tokens[token_ind]));
			}
			else
			{
				if (temp_head[0]->right != NULL)
					temp_head = &temp_head[0]->right;
				insert_right(temp_head, create_node(tokens[token_ind]));
				rotateleft(temp_head);
			}
			if (head == NULL)
				head = temp_head;
		}
		else
		{
			insert_right(temp_head, create_node(tokens[token_ind]));
		}
		token_ind++;
	}
	return  NULL;
}

int main()
{
	parser(ft_split("1234 | 91011 > 123 | 123", ' '));
	return 0;
}
