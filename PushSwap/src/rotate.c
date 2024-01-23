/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:21 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 16:27:10 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Shift up all elements of a stack by 1. 
//The first element becomes the last one | ra and rb

#include "../include/push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_lstsize_p(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast_p(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_node **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_node **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_lstsize_p(*stack_a) < 2) || (ft_lstsize_p(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
