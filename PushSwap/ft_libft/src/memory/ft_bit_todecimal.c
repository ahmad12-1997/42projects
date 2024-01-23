/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_todecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:39:46 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/20 16:41:29 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// converts binary to ascii or unicode
// returns the result as an integer
// if it's not just for comparison it prints the character
int	ft_bit_todecimal(char *s, int b_write)
{
	int				pow;
	int				c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	if (b_write == 1)
	{
		write(1, &c, 1);
		return ((char) NULL);
	}
	return (c);
}
