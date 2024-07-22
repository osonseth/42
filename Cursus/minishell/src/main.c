/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:53:25 by max               #+#    #+#             */
/*   Updated: 2024/07/21 23:53:19 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *start_variable_value(char *str)
{
	while (*str && *str != '=')
		str++;
	if (*str == '=')
		return str + 1;
	return NULL;
}

char *ft_getenv(char *name, t_data *data)
{
	int i;
	int len_name;
	char *ptr;

	len_name = ft_strlen(name);
	i = 0;
	ptr = NULL;
	while (data->shell_env[i])
	{
		if (!ft_strncmp(data->shell_env[i], name, len_name) && data->shell_env[i][len_name] == '=')
		{
			ptr = start_variable_value(data->shell_env[i]);
			return ptr;
		}
		i++;
	}

	return NULL;
}

void exec(t_data *data)
{
	char **test = ft_split(ft_getenv("PATH",data));
	
	   for (char **t = test; *t != NULL; t++)
    {
        printf("%s\n", *t);
    }
	 for (char **t = test; *t != NULL; t++)
    {
        free(*t);
    }
    free(test);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data(data) = {0};
	env_management(envp, &data);
	while (1)
	{
		data.line = readline("Minishell$");
		if (!data.line || !ft_strncmp(data.line, "exit", 4))
		{
			clean_env(&data);
			clean_all(&data);
			exit(EXIT_SUCCESS);
		}
		add_history(data.line);
		if (!parsing_management(&data))
		{
			clean_all(&data);
			continue;
		}
		exec(&data);
		print_all(&data);
		clean_all(&data);
	}
	return (0);
}
