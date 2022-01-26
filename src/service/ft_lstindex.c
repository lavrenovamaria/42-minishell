#include "../minishell.h"

t_list	*ft_lstindex(t_list *lst, int index)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = lst;
	if (lst != NULL)
	{
		while (index != count)
		{
			if (lst->next != NULL)
				tmp = tmp->next;
			else
				return NULL;
			count++;
		}
		return tmp;
	}
	return NULL;
}
