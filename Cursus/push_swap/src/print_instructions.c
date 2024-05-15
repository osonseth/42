/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:29:38 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 17:33:01 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sa(t_list **stack_a)
{
	swap_a(stack_a);
	ft_printf("sa\n");
}

void	print_sb(t_list **stack_b)
{
	swap_b(stack_b);
	ft_printf("sb\n");
}

void	print_ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}

void	print_pb(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	ft_printf("pb\n");
}

void	print_pa(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_a, stack_b);
	ft_printf("pa\n");
}
