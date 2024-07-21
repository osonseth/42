/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_tokenization.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:47:09 by max               #+#    #+#             */
/*   Updated: 2024/07/19 00:50:15 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Crée les token < , << , > ou >>
    Renvoie NULL en cas de fail malloc
*/

t_tokens *create_redirection_token(t_tokens *lst, char *str, int *i)
{
    if (!ft_strncmp(str, "<<", 2))
    {
        if (!token_node_add_back(&lst, new_token_node(heredoc_token())))
            return NULL;
        (*i)++;
    }
    else if (!ft_strncmp(str, ">>", 2))
    {
        if (!token_node_add_back(&lst, new_token_node(append_redirect_token())))
            return NULL;
        (*i)++;
    }
    else if (!ft_strncmp(str, "<", 1))
    {
        if (!token_node_add_back(&lst, new_token_node(input_redirect_token())))
            return NULL;
    }
    else if (!ft_strncmp(str, ">", 1))
    {
        if (!token_node_add_back(&lst, new_token_node(output_redirect_token())))
            return NULL;
    }
    return lst;
}
/*
Crée les tokens contenu des redirections
Renvoie NULL en cas de fail malloc
*/

t_tokens *create_redirection_token_content(t_tokens *lst, char *str, int *i)
{
    if (!token_node_add_back(&lst, new_token_node(redirection_token_content(str))))
        return NULL;
    (*i) += ft_strlen_redir_token_content(str) - 1;
    return lst;
}

/*
Divise le token en token redirections et contenu des redirections
renvoie NULL en cas de fail malloc
*/
static t_tokens *split_token(char *str)
{
    t_tokens(*lst) = NULL;
    t_tokens(*save_lst) = NULL;
    int(i) = 0;

    while (str[i])
    {
        if (is_redirection_token(&str[i]))
            lst = create_redirection_token(lst, &str[i], &i);
        else
            lst = create_redirection_token_content(lst, &str[i], &i);
        if (!lst)
        {
            clean_token_lst(&save_lst);
            return NULL;
        }
        save_lst = lst;
        if (str[i])
            i++;
    }
    return lst;
}

/*
Découpage de la fonction principale
Si le token a des redirections = decoupe le token avec split et l'ajoute a la nouvelle liste
Sinon rajoute l'ancien token a la nouvelle liste
*/

bool redir_tokenization_step(t_tokens **new_lst, t_tokens **current, t_data *data)
{
    if (have_redirections((*current)->word, data) && ft_strlen((*current)->word) > 2)
    {
        if (!token_lst_add_back(new_lst, split_token((*current)->word)))
        {

            clean_new_and_old_token_lst(new_lst, current);
            return false;
        }
        free((*current)->word);
    }
    else
    {

        if (!token_node_add_back(new_lst, new_token_node((*current)->word)))
        {

            clean_new_and_old_token_lst(new_lst, current);
            return false;
        }
    }
    return true;
}

/*
Fonction decoupé qui crée une nouvelle liste de token en rajoutant les tokens de redirections et leur contenu si le token de base en contient
*/
bool redir_tokenization(t_tokens **lst, t_commands_table *table, t_data *data)
{
    t_tokens *current = *lst;
    t_tokens *new_lst = NULL;
    t_tokens *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        if (!redir_tokenization_step(&new_lst, &current, data))
        {
            table->token = NULL;
            return false;
        }
        free(current);
        current = next_node;
    }
    *lst = new_lst;
    return true;
}
