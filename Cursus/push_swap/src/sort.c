/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:43:06 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 18:48:30 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	t_list	*current;
	t_list	*node2;
	t_list	*node3;

	current = *lst;
	node2 = (*lst)->next;
	node3 = node2->next;
	if (current->value > node2->value && node3->value > current->value)
		print_sa(lst);
	else if (current->value > node3->value && node3->value > node2->value)
		print_ra(lst);
	else if (node2->value > current->value && current->value > node3->value)
		print_rra(lst);
	else if (node2->value > node3->value && node3->value > current->value)
	{
		print_sa(lst);
		print_ra(lst);
	}
	else if (node3->value < node2->value && node2->value < current->value)
	{
		print_ra(lst);
		print_sa(lst);
	}
	else
		return ;
}

void	sort_four(t_data *data, t_list **a, t_list **b)
{
	int	number;

	number = data->array_number_height;
	while (number > 3)
	{
		if ((*a)->is_max == true || (*a)->is_min == true)
		{
			print_pb(a, b);
			number--;
		}
		else
			print_ra(a);
	}
	sort_three(a);
	print_pa(a, b);
	if ((*a)->is_min == true)
		return ;
	if ((*a)->is_max == true)
		print_ra(a);
}

void	sort_five(t_data *data, t_list **a, t_list **b)
{
	int	number;

	number = data->array_number_height;
	while (number > 3)
	{
		if ((*a)->is_max == true || (*a)->is_min == true)
		{
			print_pb(a, b);
			number--;
		}
		else
			print_ra(a);
	}
	sort_three(a);
	print_pa(a, b);
	if ((*a)->is_min == true)
	{
		print_pa(a, b);
		print_ra(a);
	}
	if ((*a)->is_max == true)
	{
		print_ra(a);
		print_pa(a, b);
	}
}
