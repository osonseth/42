/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:54 by max               #+#    #+#             */
/*   Updated: 2024/07/06 13:06:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void memory_error(t_data *data)
{
    clean_all(data);
    perror("malloc failed");
    exit(EXIT_FAILURE);
}

void print_syntax_error(int type)
{
    if (type == PIPE)
        write(2, "Minishell: syntax error near unexpected token '|'\n", 50);
    if (type == QUOTE)
        write(2, "Minishell: syntax error - unclosed quotes\n", 43);
}
