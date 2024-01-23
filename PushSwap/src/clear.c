/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:17:54 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 20:18:59 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstclear_int(t_node **lst, void (*del)(void **))
{
	t_node	*head_tmp;

	if (!lst || !(*lst) || !del)
		return ;
	head_tmp = *lst;
	while (head_tmp != NULL)
	{
		head_tmp = head_tmp->next;
		free(*lst);
		*lst = head_tmp;
	}
	*lst = NULL;
}

void	free_and_exit_with_message(t_stacks *s, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (s != NULL)
	{
		if (s->stack_a != NULL)
			ft_lstclear_int(&(s->stack_a), ft_lstdelcont);
		if (s->stack_b != NULL)
			ft_lstclear_int(&(s->stack_b), ft_lstdelcont);
		free(s->joined_args);
		s->joined_args = NULL;
		ft_arrfree(s->splited_args);
		s->splited_args = NULL;
	}
	exit(0);
}
