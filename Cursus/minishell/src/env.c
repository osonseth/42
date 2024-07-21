/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:08:06 by max               #+#    #+#             */
/*   Updated: 2024/07/21 18:13:24 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *safe_strdup(const char *s, t_data *data)
{
    char *dup = strdup(s);
    if (!dup)
        memory_error(data);
    return dup;
}

void create_own_env(t_data *data)
{
    (void)data;

    data->shell_env = ft_calloc((size_t)5, sizeof(char *));
    if (!data->shell_env)
        memory_error(data);
    data->shell_env[0] = safe_strdup(ENV_USER, data);
    data->shell_env[1] = safe_strdup(ENV_HOME, data);
    data->shell_env[2] = safe_strdup(ENV_PWD, data);
    data->shell_env[3] = safe_strdup(ENV_PATH, data);
    data->shell_env[4] = NULL;
}

void env_management(char **envp, t_data *data)
{
    int size;
    size = 0;

    if (envp[0] == NULL)
        create_own_env(data);
    else
    {
        int i;
        i = 0;
        while (envp[size] != NULL)
            size++;
        data->shell_env = ft_calloc((size_t)(size + 1), sizeof(char *));
        if (!data->shell_env)
            memory_error(data);
        while (envp[i] != NULL)
        {
            data->shell_env[i] = ft_strdup(envp[i]);
            if (!data->shell_env[i])
                memory_error(data);
            i++;
        }
    }
}
