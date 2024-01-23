/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:01:55 by akanbari          #+#    #+#             */
/*   Updated: 2023/12/12 22:16:40 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_libft/includes/libft.h"
# include "../ft_libft/includes/get_next_line.h"
# include "../ft_libft/includes/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*joined_args;
	char	**splited_args;
	int		atol_sign;
}				t_stacks;

void	index_stack(t_stacks *stack);
int		is_sorted(t_node **stack);
void	free_stack(t_node **stack);
int		ft_lstsize_p(t_node *head);
void	print_linkedlst(t_node *head);
void	ft_lstadd_back_p(t_node **stack, t_node *new);
t_node	*ft_lstlast_p(t_node *head);
void	ft_lstadd_front_p(t_node **stack, t_node *new);
t_node	*ft_lstnew_p(int value);
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	simple_sort(t_node **stack_a, t_node **stack_b, t_stacks *s);
int		get_distance(t_node **stack, int index);
void	free_and_exit_with_message(t_stacks *s, char *msg);
long	ft_atol_p(const char *str, t_stacks *s);
int		swap(t_node **stack, t_stacks *s);
int		sa(t_node **stack_a_node, t_stacks *s);
int		sb(t_node **stack_b_node, t_stacks *s);
int		ss(t_stacks *s);
int		push(t_node **stack_to, t_node **stack_from);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_a, t_node **stack_b);
int		rotate(t_node **stack);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		reverseRotate(t_node **stack);
int		rra(t_node **stack_a);
int		rrb(t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);
void	ft_check_args(char **argv, t_stacks *s);
int		get_min(t_node **stack, int val);

#endif
