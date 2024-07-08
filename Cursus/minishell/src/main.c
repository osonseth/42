/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:53:25 by max               #+#    #+#             */
/*   Updated: 2024/07/07 00:44:03 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_data(data) = {0};
	while (1)
	{
		data.line = readline("Minishell$");
		if (!ft_strncmp(data.line, "exit", 4))
		{
			clean_all(&data);
			exit(EXIT_SUCCESS);
		}
		parsing_management(&data);
		print_cmd_table(&data);
		clean_all(&data);
	}
	// data.line = readline("Minishell$");
	// parsing_management(&data);
	// print_cmd_table(&data);
	// clean_all(&data);
	return (0);
}
