/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/14 19:07:20 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs_ps(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	two_above_median(t_list **lst1, t_list **lst2)
{
	int	min;

	if ((*lst1)->index <= (*lst2)->index)
		min = (*lst1)->index;
	else
		min = (*lst2)->index;
	(*lst1)->cost = (*lst1)->index + (*lst2)->index - min;
}

void	two_below_median(t_list **lst1, t_list **lst2, t_data *data)
{
	int	min;

	if (data->len_a - (*lst1)->index <= data->len_b - (*lst2)->index)
		min = data->len_a - (*lst1)->index;
	else
		min = data->len_b - (*lst2)->index;
	(*lst1)->cost = (data->len_a - (*lst1)->index) + (data->len_b
		- (*lst2)->index) - min;
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

void	update_data_rr_ss(t_list **lst, t_data *data)
{
	t_list	*current;
	int		pos_a;
	int		pos_b;

	current = *lst;
	while (current->is_cheaper != true)
	{
		current = current->next;
	}
	data->above = current->above_median;
	pos_a = data->len_a - current->index;
	pos_b = data->len_b - current->target->index;
	if (current->above_median == true && current->target->above_median == true)
	{
		if (current->index != 0 && current->target->index != 0)
			data->rr = ft_abs_ps(current->index - current->target->index);
	}
	else if (current->above_median == false
		&& current->target->above_median == false)
	{
		if (pos_a <= pos_b)
			data->rrr = pos_a;
		else if (pos_b < pos_a)
			data->rrr = pos_b;
	}
}

void	move_rr_or_rrr(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;

	i = 0;
	if (data->rr != 0)
		while (i < data->rr)
		{
			print_rr(stack_a, stack_b);
			i++;
		}
	else if (data->rrr != 0)
		while (i < data->rrr)
		{
			print_rrr(stack_a, stack_b);
			i++;
		}
}
void	place_node(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->above == true)
	{
		while ((*stack_a)->is_cheaper != true)
			print_ra(stack_a);
	}
	else if (data->above == false)
	{
		while ((*stack_a)->is_cheaper != true)
			print_rra(stack_a);
	}
	if ((*stack_a)->target->above_median == true)
	{
		while ((*stack_a)->target != *stack_b)
			print_rb(stack_b);
	}
	else if ((*stack_a)->target->above_median == false)
	{
		while ((*stack_a)->target != *stack_b)
			print_rrb(stack_b);
	}
}

void	prepare_push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	data->rr = 0;
	data->rrr = 0;
	update_mediane(stack_a, stack_b);
	find_target_a(stack_a, stack_b);
	while ((*stack_b)->target != *stack_a)
		rotate_a(stack_a);
}

void	prepare_push_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	data->rr = 0;
	data->rrr = 0;
	update_mediane(stack_a, stack_b);
	find_target_b(stack_a, stack_b);
	calculate_the_cost(stack_a, stack_b, data);
	update_data_rr_ss(stack_a, data);
	move_rr_or_rrr(stack_a, stack_b, data);
	place_node(stack_a, stack_b, data);
}

void	sort_big(t_list **stack_a, t_list **stack_b, t_data *data)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (lst_len(stack_a) > 3)
	{
		prepare_push_b(stack_a, stack_b, data);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	// while (lst_len(stack_b) > 0)
	// {
	// 	prepare_push_a(stack_a, stack_b);
	// 	push_a(stack_a, stack_b);
	// }
	// while ((*stack_a)->is_min == false)
	// 	rotate_a(stack_a);
}

void	management(t_data *data, t_list **stack_a, t_list **stack_b)
{
	if (data->array_number_height == 3)
		sort_three(stack_a);
	else if (data->array_number_height == 4)
		sort_four(data, stack_a, stack_b);
	else if (data->array_number_height == 5)
		sort_five(data, stack_a, stack_b);
	else if (data->array_number_height > 5)
		sort_big(stack_a, stack_b, data);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	t_data(data) = {0};
	if (argc < 3)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	data.argc = argc;
	data.argv = argv;
	parsing_management(&data, &stack_a);
	management(&data, &stack_a, &stack_b);
	printf("stack a :\n");
	print_list(stack_a);
	printf("\n\n");
	printf("stack b :\n");
	print_list(stack_b);
	printf("\n\n");
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
