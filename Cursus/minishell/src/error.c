/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:54 by max               #+#    #+#             */
/*   Updated: 2024/07/03 00:58:21 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void memory_error(t_data *data)
{
    clean_all(data);
    perror("malloc failed");
    exit(EXIT_FAILURE);
}

void print_syntax_error(t_data *data, int type)
{
    if (type == PIPE)
    {
        clean_all(data);
        write(2, "Minishell: syntax error near unexpected token '|'\n", 50);
        exit(EXIT_FAILURE);
    }
    if (type == QUOTE)
    {
        clean_all(data);
        write(2, "Minishell: syntax error - unclosed quotes\n", 43);
        exit(EXIT_FAILURE);
    }
}
