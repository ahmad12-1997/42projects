/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:10:29 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:38:54 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_sort_helper(t_node **stack_a, t_node **stack_b, \
		int size, int max_bits)
{
	t_node	*head_a;
	int		i;
	int		j;

	i = 0;
	head_a = *stack_a;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize_p(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		size;
	int		max_bits;

	size = ft_lstsize_p(*stack_a);
	max_bits = get_max_bits(stack_a);
	radix_sort_helper(stack_a, stack_b, size, max_bits);
}
