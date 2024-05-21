/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 21:11:28 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	data->rr = 0;
	data->rrr = 0;
	update_mediane(stack_a, stack_b);
	find_target_a(stack_a, stack_b);
	calculate_the_cost(stack_b, stack_a, data);
	set_inmotion_b(stack_a, stack_b);
}

void	prepare_push_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	data->rr = 0;
	data->rrr = 0;
	update_mediane(stack_a, stack_b);
	find_target_b(stack_a, stack_b);
	calculate_the_cost(stack_a, stack_b, data);
	set_inmotion_a(stack_a, stack_b);
}

void	sort_big(t_list **stack_a, t_list **stack_b, t_data *data)
{
	print_pb(stack_a, stack_b);
	print_pb(stack_a, stack_b);
	while (lst_len(stack_a) > 3)
	{
		if (lst_is_shorted(*stack_a))
			break ;
		prepare_push_b(stack_a, stack_b, data);
		print_pb(stack_a, stack_b);
	}
	if (lst_len(stack_a) == 3)
		sort_three(stack_a);
	while (lst_len(stack_b) > 0)
	{
		prepare_push_a(stack_a, stack_b, data);
		print_pa(stack_a, stack_b);
	}
	while ((*stack_a)->is_min == false)
		print_ra(stack_a);
}

void	management(t_data *data, t_list **stack_a, t_list **stack_b)
{
	if (data->array_number_height == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			print_ra(stack_a);
	}
	else if (data->array_number_height == 3)
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
	t_data	data;

	data = (t_data){};
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	data.argc = argc;
	data.argv = argv;
	parsing_management(&data, &stack_a);
	management(&data, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
