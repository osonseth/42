/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:52:00 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 18:55:19 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest(t_list **lst)
{
	long int	smallest_value;
	t_list		*current;
	t_list		*smallest;

	smallest_value = LONG_MAX;
	current = *lst;
	while (current != NULL)
	{
		if (current->value < smallest_value)
		{
			smallest_value = current->value;
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

t_list	*find_bigger(t_list **lst)
{
	long int	bigger_value;
	t_list		*current;
	t_list		*bigger;

	bigger_value = LONG_MIN;
	current = *lst;
	while (current != NULL)
	{
		if (current->value > bigger_value)
		{
			bigger_value = current->value;
			bigger = current;
		}
		current = current->next;
	}
	return (bigger);
}

void	update_target_b(t_list **a, t_list **b)
{
	long int	smallest;
	long int	diff;
	t_list		*current_b;

	current_b = *b;
	smallest = LONG_MAX;
	while (current_b != NULL)
	{
		diff = (*a)->value - current_b->value;
		if (current_b->value < (*a)->value && diff < smallest)
		{
			(*a)->target = current_b;
			smallest = diff;
		}
		current_b = current_b->next;
	}
	if (smallest == LONG_MAX)
		(*a)->target = find_bigger(b);
}

void	find_target(t_list **lst1, t_list **lst2)
{
	t_list	*current_lst;

	current_lst = *lst1;
	while (current_lst != NULL)
	{
		update_target_b(&current_lst, lst2);
		current_lst = current_lst->next;
	}
}
