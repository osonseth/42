/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:53:25 by max               #+#    #+#             */
/*   Updated: 2024/07/18 19:27:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec()
{
	printf("\nON RENTRE DANS L'EXEC\n");
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data(data) = {0};
	data.shell_env = env_management(envp, &data);
	while (1)
	{
		data.line = readline("Minishell$");
		if (!ft_strncmp(data.line, "exit", 4))
		{
			clean_array(data.shell_env);
			clean_all(&data);
			exit(EXIT_SUCCESS);
		}
		if (!parsing_management(&data))
		{
			clean_all(&data);
			continue;
		}
		exec();
		print_all(&data);
		clean_all(&data);
	}
	return (0);
}
