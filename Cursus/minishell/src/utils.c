/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:38:42 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/16 00:09:05 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *skype_space_ptr(char *str)
{
    while ((*str == 9 || *str == 32) && *str)
        str++;
    return str;
}
void skype_space(char *str, int *i)
{
    while (is_space(*str) && *str)
    {
        (*i)++;
        str++;
    }
}
void free_old_node(t_tokens *node)
{
    free(node->word);
    node->word = NULL;
    free(node);
}

bool have_redirections(char *str, t_data *data)
{
   printf(" STR = %s\n",str);
    int i;
    i = 0;
    printf("quote = %d %d \n",data->double_quote,data->simple_quote);
    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);
         printf("quote dans la boucle = %d %d \n",data->double_quote,data->simple_quote);
        if ((str[i] == '<' || str[i] == '>') && !data->double_quote && !data->simple_quote)
        { printf(" return = TRUE\n");
            return true;
        }
        i++;
    }
    printf(" return = FALSE\n");
    return false;
}
