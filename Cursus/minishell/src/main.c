/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:53:25 by max               #+#    #+#             */
/*   Updated: 2024/07/03 23:47:16 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{

	t_data(data) = {0};

	data.line = readline("Minishell$");
	parsing_management(&data);
	// int lenght = calculate_expanded_lenght(&data);
	// printf("lenght = %d\n\n", lenght);
	print_cmd_table(&data);
	clean_all(&data);

	return (0);
}
