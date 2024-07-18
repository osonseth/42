/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:59:26 by max               #+#    #+#             */
/*   Updated: 2024/07/18 08:42:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_array(char **arg)
{
    int i;
    i = 0;

    while (arg[i])
        free(arg[i++]);
    free(arg[i]);
    free(arg);
}
void clean_new_and_old_token_lst (t_tokens **new,t_tokens **old)
{
    clean_token_lst(*new);
    clean_token_lst(*old);
    *new = NULL;
    *old = NULL;
}