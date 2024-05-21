/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:52:00 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 21:10:24 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	find_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_lst;

	current_lst = *stack_a;
	while (current_lst != NULL)
	{
		update_target_b(&current_lst, stack_b);
		current_lst = current_lst->next;
	}
}

void	find_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_lst;

	current_lst = *stack_b;
	while (current_lst != NULL)
	{
		update_target_a(&current_lst, stack_a);
		current_lst = current_lst->next;
	}
}

void	update_mediane(t_list **lst1, t_list **lst2)
{
	t_list	*current1;
	t_list	*current2;
	int		len1;
	int		len2;

	len1 = lst_len(lst1);
	len2 = lst_len(lst2);
	current1 = *lst1;
	current2 = *lst2;
	while (current1 != NULL)
	{
		if (current1->index < len1 / 2)
			current1->above_median = true;
		else
			current1->above_median = false;
		current1 = current1->next;
	}
	while (current2 != NULL)
	{
		if (current2->index < len2 / 2)
			current2->above_median = true;
		else
			current2->above_median = false;
		current2 = current2->next;
	}
}

void	update_cheaper(t_list **lst)
{
	t_list	*current;
	int		temp;

	current = *lst;
	temp = INT_MAX;
	while (current != NULL)
	{
		if (current->cost < temp)
			temp = current->cost;
		current = current->next;
	}
	current = *lst;
	while (current != NULL)
	{
		if (current->cost == temp)
		{
			current->is_cheaper = true;
			break ;
		}
		current = current->next;
	}
}
