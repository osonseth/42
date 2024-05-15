/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:26:25 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 21:11:45 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_the_cost(t_list **lst1, t_list **lst2, t_data *data)
{
	t_list	*current;

	data->len_a = lst_len(lst1);
	data->len_b = lst_len(lst2);
	current = *lst1;
	while (current != NULL)
	{
		if (current->above_median == true
			&& current->target->above_median == true)
			two_above_median(&current, &current->target);
		else if (current->above_median == false
			&& current->target->above_median == false)
			two_below_median(&current, &current->target, data);
		else if (current->above_median == true
			&& current->target->above_median == false)
			current->cost = current->index + (data->len_b
					- current->target->index);
		else if (current->above_median == false
			&& current->target->above_median == true)
			current->cost = (data->len_a - current->index)
				+ current->target->index;
		current = current->next;
	}
	update_cheaper(lst1);
}

void	update_target_a(t_list **b, t_list **a)
{
	long int	bigger;
	long int	diff;
	t_list		*current_a;

	current_a = *a;
	bigger = LONG_MIN;
	while (current_a != NULL)
	{
		diff = (*b)->value - current_a->value;
		if (current_a->value > (*b)->value && diff > bigger)
		{
			(*b)->target = current_a;
			bigger = diff;
		}
		current_a = current_a->next;
	}
	if (bigger == LONG_MIN)
		(*b)->target = find_smallest(a);
}

void	set_inmotion_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheap(stack_b);
	while ((cheapest->above_median && cheapest->target->above_median)
		&& (*stack_b != cheapest && *stack_a != cheapest->target))
		print_rr(stack_a, stack_b);
	while ((!cheapest->above_median && !cheapest->target->above_median)
		&& (*stack_b != cheapest && *stack_a != cheapest->target))
		print_rrr(stack_a, stack_b);
	while (*stack_b != cheapest)
	{
		if (cheapest->above_median)
			print_rb(stack_b);
		else if (!cheapest->above_median)
			print_rrb(stack_b);
	}
	while (*stack_a != cheapest->target)
	{
		if (cheapest->target->above_median)
			print_ra(stack_a);
		else if (!cheapest->target->above_median)
			print_rra(stack_a);
	}
}

t_list	*get_cheap(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (current->is_cheaper)
			return (current);
		current = current->next;
	}
	return (current);
}

void	set_inmotion_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheap(stack_a);
	while ((cheapest->above_median && cheapest->target->above_median)
		&& (*stack_a != cheapest && *stack_b != cheapest->target))
		print_rr(stack_a, stack_b);
	while ((!cheapest->above_median && !cheapest->target->above_median)
		&& (*stack_a != cheapest && *stack_b != cheapest->target))
		print_rrr(stack_a, stack_b);
	while (*stack_a != cheapest)
	{
		if (cheapest->above_median)
			print_ra(stack_a);
		else if (!cheapest->above_median)
			print_rra(stack_a);
	}
	while (*stack_b != cheapest->target)
	{
		if (cheapest->target->above_median)
			print_rb(stack_b);
		else if (!cheapest->target->above_median)
			print_rrb(stack_b);
	}
}
