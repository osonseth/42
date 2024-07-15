/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:08:06 by max               #+#    #+#             */
/*   Updated: 2024/07/15 18:03:08 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **create_own_env(t_data *data)
{
    (void)data;
    char **array;
    array = malloc(5 * sizeof(char *));
    array[0] = ft_strdup(ENV_USER);
    array[1] = ft_strdup(ENV_HOME);
    array[2] = ft_strdup(ENV_PWD);
    array[3] = ft_strdup(ENV_PATH);
    array[4] = NULL;
    return array;
}

char **env_management(char **envp, t_data *data)
{
    char **my_env;
    int size;
    size = 0;

    // if (envp[0] == NULL)
    if (envp[0] == NULL || !ft_strncmp(envp[0], "LD_LIBRARY_PATH=/usr/lib/debug", 30))
        my_env = create_own_env(data);
    else
    {
        int i;
        i = 0;
        while (envp[size] != NULL)
            size++;
        my_env = malloc((size + 1) * sizeof(char *));
        while (envp[i] != NULL)
        {
            my_env[i] = ft_strdup(envp[i]);
            i++;
        }
        my_env[i] = NULL;
    }
    return my_env;
}
