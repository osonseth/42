/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 20:05:25 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void calculate_the_cost(t_list **stack_a, t_list **stack_b)
// {

// }

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	lst_len(stack_b);
	lst_len(stack_a);
	find_target(stack_a, stack_b);
	// while (lst_len(*stack_a) > 3)
	// {
	// 	find_target(stack_a, stack_b);
	// }
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
		sort_big(stack_a, stack_b);
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
	print_list(stack_a);
	printf("\n\n");
	print_list(stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
