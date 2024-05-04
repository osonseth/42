/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/04 02:06:58 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	management(t_data *data, t_list **stack_a, t_list **stack_b)
{
	print_list(*stack_a);
	ft_printf("\n\n");
	printf(" on s'en fou %d\n\n", data->array_number_height);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	print_list(*stack_a);
	ft_printf("\n\n");
	print_list(*stack_b);
	ft_printf("\n\n");
	reverse_rotate_a_and_b(stack_a, stack_b);
	reverse_rotate_a_and_b(stack_a, stack_b);
	print_list(*stack_a);
	ft_printf("\n\n");
	print_list(*stack_b);
	ft_printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	t_data(data) = {0};
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	data.argc = argc;
	data.argv = argv;
	parsing_management(&data, &stack_a);
	management(&data, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
