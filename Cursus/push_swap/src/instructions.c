/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:35:08 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 08:49:55 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp_next;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	temp = *stack_a;
	temp_next = (*stack_a)->next;
	temp->next = temp_next->next;
	temp_next->next = temp;
	*stack_a = temp_next;
}

void	swap_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp_next;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	temp_next = (*stack_b)->next;
	temp->next = temp_next->next;
	temp_next->next = temp;
	*stack_b = temp_next;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}
