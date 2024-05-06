/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:12:33 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 09:04:59 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*first_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first_node = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = first_node;
	*stack_a = first_node->next;
	first_node->next = NULL;
}

void	rotate_b(t_list **stack_b)
{
	t_list	*first_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_node = *stack_b;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = first_node;
	*stack_b = first_node->next;
	first_node->next = NULL;
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*prev_node;
	t_list	*last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	prev_node = NULL;
	last_node = *stack_a;
	while (last_node->next != NULL)
	{
		prev_node = last_node;
		last_node = last_node->next;
	}
	prev_node->next = NULL;
	last_node->next = *stack_a;
	*stack_a = last_node;
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*prev_node;
	t_list	*last_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	prev_node = NULL;
	last_node = *stack_b;
	while (last_node->next != NULL)
	{
		prev_node = last_node;
		last_node = last_node->next;
	}
	prev_node->next = NULL;
	last_node->next = *stack_b;
	*stack_b = last_node;
}

void	print_rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
