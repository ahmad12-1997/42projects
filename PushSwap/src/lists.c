/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:52:44 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:20:28 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Creates new node and returns the pointer of it
t_node	*ft_lstnew_p(int value)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_lstadd_front_p(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the last node of a list 
t_node	*ft_lstlast_p(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_lstadd_back_p(t_node **stack, t_node *new)
{
	t_node	*n;

	if (*stack)
	{
		n = ft_lstlast_p(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Returns the size of the Linked List
int	ft_lstsize_p(t_node *head)
{
	size_t	i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
