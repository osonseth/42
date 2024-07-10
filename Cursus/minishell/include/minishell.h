/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/10 18:31:03 by max              ###   ########.fr       */
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
#define CLOSING_BRACE 125

typedef enum
{
	HEREDOC,
	OUTFILE,
	INFILE,
	APPEND

} e_redirection_type;

typedef union
{
	char *heredoc_content;
	char *filename;

} u_redirection_data;

typedef struct s_variable
{
	char *value;
	struct s_variable *next;
} t_variable;

typedef struct s_redirects
{
	e_redirection_type type;
	u_redirection_data data;
	struct s_redirects *next;

} t_redirects;

typedef struct s_tokens
{
	char *word;
	struct s_tokens *next;

} t_tokens;

typedef struct s_commands_table
{
	bool syntaxe_error;
	char *message_error;
	char *simple_cmd;
	char **args;
	t_tokens *token;
	t_redirects *redirects;
	struct s_commands_table *next;

} t_commands_table;

typedef struct data
{
	t_commands_table *table;
	t_variable *variable;
	char *line;
	bool simple_quote;
	bool double_quote;

} t_data;

// ------------------------------ List variable ----------------------------------------------
void variable_node_add_back(t_variable **lst, t_variable *new, t_data *data);
t_variable *new_variable_node(void *content);
// ------------------------------ List cmd_table ----------------------------------------------
t_commands_table *new_cmd_table_node(void *content);
void cmd_table_node_add_back(t_commands_table **lst, t_commands_table *new, t_data *data);
void build_cmd_table(t_data *data);
//------------------------ List token node & token word ---------------------------------------
t_tokens *new_token_node(void *content);
void token_node_add_back(t_tokens **lst, t_tokens *new, t_data *data);
int create_token(char *str, t_commands_table *table, t_data *data);
void node_tokenization(t_data *data, t_commands_table *table);
//------------------------------------ Quote --------------------------------------------------
void opening_and_closing_quotes(char c, t_data *data);
bool quote_syntax_errors(t_data *data);
void quotes_reset(t_data *data);
//-------------------------- check syntax pipe & expand----------------------------------------
bool pipe_syntax_errors(t_data *data);
bool expand_has_syntax_errors(t_commands_table *table, t_data *data);
//---------------------------------- Core parsing ---------------------------------------------
void parsing_management(t_data *data);
void recursive_handle_command_node(t_data *data, t_commands_table *table);

// --------------------------------- Clean memory ----------------------------------------------
void clean_variable_lst(t_variable *lst);
void clean_cmd_table(t_data *data);
void clean_all(t_data *data);
// -------------------------------- Message d'erreur -------------------------------------------
void memory_error(t_data *data);
void print_syntax_error(int type);
//---------------------------- pour tester, a supprimer ----------------------------------------
void print_cmd_table(t_data *data);
void print_tokens(t_data *data);
void print_variable_value(t_data *data);
// ---------------------------------- Expand functions ---------------------------------------------
char *expand_management(char *word, t_data *data);
bool no_expand(char *word, t_data *data);
int make_var_value_lst_and_calculate_len(char *var_name, t_data *data);
int calculate_variable_value_without_brace_len(char *word, t_data *data);
int calculate_variable_value_brace_len(char *word, t_data *data);
int calculate_expanded_len(char *word, t_data *data);
// ---------------------------------- Expand utils -------------------------------------------------
int skip_to_closing_brace(char *word);
int skip_to_end_of_variable(char *word);
int ft_strlen_variable_name_without_brace(char *word);
int ft_strlen_variable_name_with_brace(char *word);
void ft_strncpy_variable_name(char *dest, char *src, int len);
// ------------------------------------- Utils -------------------------------------------------
char *skype_space_ptr(char *string);
void skype_space(char *str, int *i);

#endif