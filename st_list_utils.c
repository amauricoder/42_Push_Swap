/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:14 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/05 22:50:32 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Create a new node with the value of the input
//initialize all other values with 0 or NULL.
t_stack	*st_newitem(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->qt_mov_top = 0;
	new->above_med = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

//Add a node to the end of the list.
void	st_item_addback(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

//Free all nodes of a list
void	st_list_free(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/* int main(void)
{
	int	value_insert = 42;
	t_stack *new_node;

	new_node = list_newitem(value_insert);
	if (new_node != NULL)
		ft_printf("Stack node created successfully. Value: %d\n", new_node->value);
	else
		ft_printf("Failed to create stack node.\n");
	free(new_node);
} */
/* 
int main(void)
{
	t_stack *list;
	t_stack *current;
	t_stack *new;
	
	list = st_newitem(1);
	list->next = st_newitem(2);
	list->next->next = st_newitem(3);
	list->next->next->next = st_newitem(4);

	new = st_newitem(5);
	st_item_addback(&list, new);
	current = list;
	while(current != NULL)
	{
		ft_printf("%i\n", current->value);
		current = current->next;
	}
}  */