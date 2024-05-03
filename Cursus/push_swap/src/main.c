/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/03 18:04:38 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (1);
	t_data(data) = {0};
	// t_list(stack_b) = {0};
	stack_a = NULL;
	data.argc = argc;
	data.argv = argv;
	parsing_management(&data, &stack_a);
	
	// print_list(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
