/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:59:26 by max               #+#    #+#             */
/*   Updated: 2024/07/21 19:34:50 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_args(char **args)
{
    if (args == NULL)
        return;
    int i;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        args[i] = NULL;
        i++;
    }
    free(args);
    args = NULL;
}

void clean_env(t_data *data)
{
    if (!data->shell_env)
        return;
    int i;
    i = 0;

    while (data->shell_env[i])
    {
        free(data->shell_env[i]);
        data->shell_env[i++] = NULL;
    }
    free(data->shell_env);
    data->shell_env = NULL;
}
void clean_new_and_old_token_lst(t_tokens **new, t_tokens **old)
{
    clean_token_lst(new);
    clean_token_lst(old);
}