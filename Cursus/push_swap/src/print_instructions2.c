/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:38:19 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 15:31:46 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ra(t_list **stack_a)
{
	rotate_a(stack_a);
	ft_printf("ra\n");
}

void	print_rb(t_list **stack_b)
{
	rotate_b(stack_b);
	ft_printf("rb\n");
}

void	print_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}

void	print_rra(t_list **stack_a)
{
	reverse_rotate_a(stack_a);
	ft_printf("rra\n");
}

void	print_rrb(t_list **stack_b)
{
	reverse_rotate_b(stack_b);
	ft_printf("rrb\n");
}
