/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:54 by max               #+#    #+#             */
/*   Updated: 2024/07/21 19:32:35 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void memory_error(t_data *data)
{
    clean_env(data);
    perror("malloc failed");
    exit(EXIT_FAILURE);
}

void print_syntax_error(int type)
{
    if (type == PIPE)
        write(2, "Minishell: syntax error near unexpected token '|'\n", 50);
    if (type == QUOTE)
        write(2, "Minishell: syntax error - unclosed quotes\n", 43);
    if (type == OUTFILE)
        write(2, "Minishell: syntax error near unexpected token '>'\n", 50);
    if (type == INFILE)
        write(2, "Minishell: syntax error near unexpected token '<'\n", 50);
    if (type == APPEND)
        write(2, "Minishell: syntax error near unexpected token '>>'\n", 51);
    if (type == HEREDOC)
        write(2, "Minishell: syntax error near unexpected token '<<'\n", 51);
}
