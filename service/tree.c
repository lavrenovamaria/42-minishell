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
	tree->height = 1;

	return (tree);
}

t_tree	*rotateright(t_tree *root)
{
	t_tree *temp = root->left;
	temp->right = root;
	root = temp;
}

void	rotateleft(t_tree *root)
{
	t_tree *temp = root->right;
	temp->left = root;
	root = temp;
}

void	insert_right(t_tree* root, t_tree *node)
{
	if (root)
		root->right = node;
	else
		root = node;
}

void	insert_left(t_tree* root, t_tree *node)
{
	if (root)
		root->left = node;
	else
		root = node;
}

