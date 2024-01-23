/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:40:23 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:30:26 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	if_duplicate(int num, char **argv, int i)
{
	int	j;

	j = 1;
	while (argv[j] && j < i)
	{
		if (ft_atol(argv[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_isnumeric(char *num)
{
	int	i;

	i = 0;
	if (num[0] && (num[0] == '-' || num[0] == '+'))
		i++;
	if (num[i] == '\0')
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(char **argv, t_stacks *s)
{
	int		i;
	long	tmp;
	char	**args;

	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atol_p(args[i], s);
		if (!ft_isnumeric(args[i]))
			free_and_exit_with_message(s, "Error");
		if (if_duplicate(tmp, args, i))
			free_and_exit_with_message(s, "Error");
		if (tmp > INT_MAX || tmp < INT_MIN)
			free_and_exit_with_message(s, "Error");
		i++;
	}
}

// Prints the Linked List
void	print_linkedlst(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
