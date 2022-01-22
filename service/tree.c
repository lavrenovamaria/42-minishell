#include "../minishell.h"

void	free_tree(t_tree *root)
{
	if (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

t_tree	*create_node(void *content)
{
	t_tree *tree;

	tree = malloc(sizeof(t_tree));
	if (tree == NULL)
		return (NULL);
	tree->content = content;
	tree->left = NULL;
	tree->right = NULL;
	tree->head = NULL;
	tree->height = 1;

	return (tree);
}

void	rotateright(t_tree **root)
{
	t_tree *temp = root[0]->left;
	temp->right = root[0];
	temp->head = root[0]->head;
	root[0]->left = NULL;
	root[0]->head = temp;
	root[0] = temp;
}

void	rotateleft(t_tree **root)
{
	t_tree *temp = root[0]->right;
	temp->left = root[0];
	temp->head = root[0]->head;
	root[0]->right = NULL;
	root[0]->head = temp;
	root[0] = temp;
}

void	insert_right(t_tree** root, t_tree *node)
{
	if (root[0])
	{
		root[0]->right = node;
		root[0]->right->head = root[0];
	}
	else
		root[0] = node;
}

void	insert_left(t_tree** root, t_tree *node)
{
	if (root[0])
	{
		root[0]->left = node;
		root[0]->right->head = root[0];
	}
	else
		root[0] = node;
}

void	insert_up(t_tree** root, t_tree *node)
{
	t_tree *temp;
	t_tree *head;

	if (root[0])
	{
		temp = root[0];
		head = root[0]->head;
		head->right = node;
		node->head = head;
		node->left = temp;
		temp->head = node;
		root[0] = node;
	}
	else
		root[0] = node;
}

