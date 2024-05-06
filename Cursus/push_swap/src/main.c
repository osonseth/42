/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 08:00:46 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	management(t_data *data, t_list **stack_a, t_list **stack_b)
{
	print_list(*stack_b);
	printf("\n\n");
	printf("on s en fou%d\n\n", data->array_number_height);
	printf("\n\n");
	printf("-----------------------------------------");
	printf("\n\n");
	print_list(*stack_a);
	printf("\n\n");
	if (lst_is_shorted(*stack_a))
		printf("liste trier");
	else
		printf("liste non trier");
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
