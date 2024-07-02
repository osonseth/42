/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/03 01:02:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PIPE 0
#define QUOTE 1

typedef struct s_redirects
{
	int type;
	char *filename;
	struct s_redirects *next;
} t_redirects;

typedef struct s_commands_table
{	bool syntaxe_error;
	char *message_error;
	char *simple_cmd;
	char **args;
	struct s_commands_table *next;
	t_redirects *redirects;

} t_commands_table;

typedef struct data
{
	t_commands_table *table;
	char *line;
	bool simple_quote;
	bool double_quote;

} t_data;
//---------------------------------------------------------------------------------
int calculate_expanded_words(char *str);
int calculate_expanded_lenght(t_data *data);
int strlen_variable_name(char *str);
void end_of_the_variable_name(char *str, int *i);
//-----------------------------------------------------------------------------------

bool next_node_is_empty(char *str);
void check_pipe(t_data *data);
void parsing_management(t_data *data);
void recursive_handle_command_node(t_data *data, t_commands_table *table);
void opening_and_closing_quotes(char c, t_data *data);
void check_quote(t_data *data);
//--------------------------------------------------------------------------------

t_commands_table *new_cmd_table_node(void *content);
void cmd_table_node_add_back(t_commands_table **lst, t_commands_table *new, t_data *data);
void build_cmd_table(t_data *data);

void clean_cmd_table(t_data *data);
void clean_all(t_data *data);

bool next_node_is_empty(char *str);

void memory_error(t_data *data);
void print_syntax_error(t_data *data, int type);

//-------------------------------------- pour tester, a supprimer
void print_cmd_table(t_data *data);
//-------------------------------------


char *skype_space_ptr(char *str);

/*
void ft_lstadd_back(t_node **lst, t_node *new);
t_node *ft_lstnew(void *content);
void make_lst(char *str, t_node **lst);
void pipe_token(t_node **lst);
void heredoc_token(t_node **lst, int *i);
void append_redirect_token(t_node **lst, int *i);
void output_redirect_token(t_node **lst);
void input_redirect_token(t_node **lst);
void create_token(char *str, t_node **lst, int *i);
*/

#endif