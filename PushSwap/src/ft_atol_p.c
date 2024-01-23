/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:43:52 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:21:20 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol_helper(const char *str, t_llint result, int *i, \
	t_stacks *s);

long	ft_atol_p(const char *str, t_stacks *s)
{
	int		i;
	int		reverse;
	t_llint	result;

	result = 0;
	i = 0;
	reverse = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			reverse *= -1;
		i++;
	}
	result = 0;
	s->atol_sign = reverse;
	result = ft_atol_helper(str, result, &i, s);
	return (result);
}

static long	ft_atol_helper(const char *str, t_llint result, int *i, t_stacks *s)
{
	long long	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = str[(*i)++] - '0';
		if (result > ((LLONG_MAX - num) / 10))
			return (free_and_exit_with_message(s, "Error"), 0);
		if ((result * -1) < ((LLONG_MIN + num) / 10))
			return (free_and_exit_with_message(s, "Error"), 0);
		result = result * 10 + num;
	}
	return ((result) * (s->atol_sign));
}
