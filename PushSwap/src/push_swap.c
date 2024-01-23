/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:07:44 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 23:19:06 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	initial_args_validation(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit(0);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error");
			j++;
		}
	}
}

static void	init_stack(t_stacks *stacks, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 1;
	stacks->joined_args = ft_strjoin_delim(argc, argv, " ");
	stacks->splited_args = ft_split(stacks->joined_args, ' ');
	ft_check_args(stacks->splited_args, stacks);
	while (stacks->splited_args[i])
	{
		new = ft_lstnew_p(ft_atol(stacks->splited_args[i]));
		ft_lstadd_back_p(&stacks->stack_a, new);
		i++;
	}
	index_stack(stacks);
	ft_arrfree(stacks->splited_args);
	free(stacks->joined_args);
}

static void	sort_stack(t_stacks *s)
{
	if (ft_lstsize_p(s->stack_a) <= 5)
		simple_sort(&s->stack_a, &s->stack_b, s);
	else
		radix_sort(&s->stack_a, &s->stack_b);
}

int	empty_string_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			return (ft_putendl_fd("Error", 2), 0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (!empty_string_checker(argv))
		return (0);
	initial_args_validation(argc, argv);
	s.stack_a = NULL;
	s.stack_b = NULL;
	s.splited_args = NULL;
	s.joined_args = NULL;
	init_stack(&s, argc, argv);
	if (is_sorted(&s.stack_a))
	{
		free_stack(&s.stack_a);
		free_stack(&s.stack_b);
		return (0);
	}
	sort_stack(&s);
	free_stack(&s.stack_a);
	free_stack(&s.stack_b);
	return (0);
}
