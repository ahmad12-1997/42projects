/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:13:33 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 20:03:48 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
