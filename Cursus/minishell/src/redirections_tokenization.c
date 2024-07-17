/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_tokenization.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:47:09 by max               #+#    #+#             */
/*   Updated: 2024/07/16 11:45:38 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_strcpy_redir_token(char *dst, const char *src)
{
    size_t i;

    i = 0;
    while (src[i] && src[i] != '<' && src[i] != '>')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int ft_strlen_redir_token(char *str)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i] && str[i] != '<' && str[i] != '>')
        i++;
    return (i);
}

char *ft_strdup_redir_token(char *s)
{
    char *dest;

    dest = malloc(1 + ft_strlen_redir_token(s) * sizeof(char));
    if (!dest)
        return (NULL);
    ft_strcpy_redir_token(dest, s);

    return (dest);
}
/*
Envoie le token a différentes sous fonction pour le diviser selon le type de redirection
*/
static t_tokens *split_token(char *str, t_data *data)
{
    t_tokens *lst;
    int i;

    lst = NULL;
    i = 0;

    while (str[i])
    {
        if (!ft_strncmp(&str[i], "<<", 2))
            heredoc_token(&lst, &i, data);
        else if (!ft_strncmp(&str[i], ">>", 2))
            append_redirect_token(&lst, &i, data);
        else if (!ft_strncmp(&str[i], ">", 1))
            output_redirect_token(&lst, data);
        else if (!ft_strncmp(&str[i], "<", 1))
            input_redirect_token(&lst, data);
        else if (str[i] != '\0')
            create_normal_token(&str[i], &lst, &i, data);
        if (str[i])
            i++;
    }
    return lst;
}

/*
Split les tokens contenant des redirections et les rajoute dans l'odre a la liste de token
next node             = save le pointeur du prochain noeud
data new et old list  = save les pointeurs de la nouvelle liste et du noeud ou l'ont se trouve dans l'ancienne liste afin de clean en cas de fail malloc
have redirection      = si redirections dans le token le divise, l'ajoute a la nouvelle liste et free l'ancien noeud
si pas de redirection = ajoute le noeud de l'ancienne liste a la nouvelle et free l'ancien
*/
void redir_tokenization(t_tokens **lst, t_data *data)
{
    t_tokens(*current) = *lst;
    t_tokens(*new_lst) = NULL;
    t_tokens *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        data->new_lst = new_lst;
        data->old_lst = current;
        if (have_redirections(current->word,data))
        {
            t_tokens *new_tokens = split_token(current->word, data);
            token_lst_add_back(&new_lst, new_tokens);
            free_old_node(current);
            current = next_node;
            continue;
        }
        token_node_add_back(&new_lst, new_token_node(current->word), data);
        free(current);
        current = next_node;
    }
    data->new_lst = NULL;
    data->old_lst = NULL;
    *lst = new_lst;
}
