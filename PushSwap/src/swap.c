/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:02:36 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 23:18:42 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swaps first two elements of a stack | sa and sb
int	swap(t_node **stack, t_stacks *s)
{
	t_node	*head;
	t_node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize_p(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		free_and_exit_with_message(s, "Error While Swapping\n");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_node **stack_a_node, t_stacks *s)
{
	if (swap(stack_a_node, s) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_node **stack_b_node, t_stacks *s)
{
	if (swap(stack_b_node, s) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stacks *s)
{
	if ((ft_lstsize_p(s->stack_a) < 2) || (ft_lstsize_p(s->stack_b) < 2))
		return (-1);
	swap(&s->stack_a, s);
	swap(&s->stack_b, s);
	ft_putendl_fd("ss", 1);
	return (0);
}
