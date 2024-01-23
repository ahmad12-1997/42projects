/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:11:37 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:31:41 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	sort_3_helper(t_node **stack_a, t_stacks *s, int min, \
		int next_min)
{
	t_node	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != next_min)
	{
		rra(stack_a);
		sa(stack_a, s);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a, s);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a, s);
			rra(stack_a);
		}
	}
}

static void	sort_3(t_node **stack_a, t_stacks *s)
{
	int		min;
	int		next_min;

	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	sort_3_helper(stack_a, s, min, next_min);
}

static void	sort_4(t_node **stack_a, t_node **stack_b, t_stacks *s)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a, s);
	pa(stack_a, stack_b);
}

void	sort_5(t_node **stack_a, t_node **stack_b, t_stacks *s)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, s);
	pa(stack_a, stack_b);
}

void	simple_sort(t_node **stack_a, t_node **stack_b, t_stacks *s)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize_p(*stack_a) == 0
		|| ft_lstsize_p(*stack_a) == 1)
		return ;
	size = ft_lstsize_p(*stack_a);
	if (size == 2)
		sa(stack_a, s);
	else if (size == 3)
		sort_3(stack_a, s);
	else if (size == 4)
		sort_4(stack_a, stack_b, s);
	else if (size == 5)
		sort_5(stack_a, stack_b, s);
}
