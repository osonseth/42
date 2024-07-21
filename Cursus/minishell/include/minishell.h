/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:41:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/07/21 21:55:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "define.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #define PIPE 124
// #define QUOTE 34
// #define CLOSING_BRACE 125

typedef enum
{
	HEREDOC,
	OUTFILE,
	INFILE,
	APPEND

} e_redirection_type;

typedef struct s_variable
{
	char *value;
	struct s_variable *next;
} t_variable;

typedef struct s_redirects
{
	e_redirection_type type;
	char *content;
	struct s_redirects *next;
} t_redirects;

typedef struct s_tokens
{
	bool not_redir;
	char *word;
	struct s_tokens *next;

} t_tokens;

typedef struct s_commands_table
{
	char *simple_cmd;
	bool syntaxe_error;
	char *message_error;
	char **args;
	t_tokens *token;
	t_redirects *redirects;
	struct s_commands_table *next;

} t_commands_table;

typedef struct data
{
	bool simple_quote;
	bool double_quote;
	bool syntax_error;
	bool error;
	char *line;
	char **shell_env;
	t_commands_table *table;
	t_variable *variable;

} t_data;


//----------------------------------- ARGS ------------------------------------------------------
char **create_args_array(t_commands_table *table);
//------------------------------------ ENV ----------------------------------------------------
void env_management(char **envp, t_data *data);
// ------------------------------ List variable ----------------------------------------------
bool variable_node_add_back(t_variable **lst, t_variable *new);
t_variable *new_variable_node(void *content);
// ------------------------------ List cmd_table ----------------------------------------------
t_commands_table *new_cmd_table_node(void *content);
bool cmd_table_node_add_back(t_commands_table **lst, t_commands_table *new);
bool build_cmd_table(t_data *data);
char *ft_strdup_simple_cmd(char *s, t_data *data);
// ------------------------------ List redirections ----------------------------------------------

bool create_redirection_lst(t_tokens *lst, t_redirects **redirection_lst);
t_redirects *create_redirection_node(t_tokens *token, t_redirects *list);
t_redirects *new_redirection_node(char *content, e_redirection_type type);
t_redirects *redirection_node_add_back(t_redirects *lst, t_redirects *new);
//------------------------------ Redirections token ---------------------------------------------
t_tokens *create_redirection_token(t_tokens *lst, char *str, int *i);
t_tokens *create_redirection_token_content(t_tokens *lst, char *str, int *i);
int ft_strlen_redir_token_content(char *str);
char *redirection_token_content(char *str);
char *heredoc_token(void);
char *append_redirect_token(void);
char *output_redirect_token(void);
char *input_redirect_token(void);
//----------------------------- Redirections tokenization ---------------------------------------
char *ft_strdup_redir_token_content(char *s);
int ft_strlen_redir_token_content(char *str);
void ft_strcpy_redir_token_content(char *dst, const char *src);
bool create_token(char *str, t_commands_table *table, t_data *data, int *i);
bool redir_tokenization(t_tokens **lst, t_commands_table *table, t_data *data);
//---------------------------------- List token node ---------------------------------------
bool token_lst_add_back(t_tokens **new_lst, t_tokens *lst);
t_tokens *new_token_node(void *content);
bool token_node_add_back(t_tokens **lst, t_tokens *new);
bool node_tokenization(t_data *data, t_commands_table *table);

//------------------------------------ Quote --------------------------------------------------
void opening_and_closing_quotes(char c, t_data *data);
bool quote_syntax_errors(t_data *data);
void quotes_reset(t_data *data);
char *remove_unnecessary_quotes(char *word, t_data *data);
//-------------------------- check syntax pipe & expand & redirections----------------------------------------
bool pipe_syntax_errors(t_data *data);
bool expand_has_syntax_errors(t_commands_table *table, t_data *data);
int redirection_syntax_errors(t_tokens *token);
bool is_redirection_token(char *word);
//---------------------------------- Core parsing ---------------------------------------------
bool parsing_management(t_data *data);
bool recursive_handle_command_node(t_data *data, t_commands_table *table);
// --------------------------------- Clean memory ----------------------------------------------
void clean_redirection_lst(t_redirects *lst);
void clean_new_and_old_token_lst(t_tokens **new, t_tokens **old);
void clean_token_lst(t_tokens **lst);
void clean_variable_lst(t_data *data);
void clean_cmd_table(t_data *data);
void clean_args(char **args);
void clean_env(t_data *data);
void clean_all(t_data *data);
// -------------------------------- Message d'erreur -------------------------------------------
void memory_error(t_data *data);
void print_syntax_error(int type);
//---------------------------- pour tester, a supprimer ----------------------------------------
void print_cmd_table(t_data *data);
void print_tokens(t_data *data);
void print_variable_value(t_data *data);
void print_array(char **array);
void print_all(t_data *data);
void print_lst(t_redirects *lst);
void print_lst2(t_tokens *lst);
// ---------------------------------- Expand functions ---------------------------------------------
char *expand_management(char *word, t_data *data);
bool recursive_handle_expand_token(t_tokens *token, t_data *data);
bool no_expand(char *word, t_data *data);
int make_var_value_lst_and_calculate_len(char *var_name, t_data *data);
int calculate_variable_value_with_brace_len(char *word, t_data *data);
int calculate_variable_value_without_brace_len(char *word, t_data *data);
int calculate_expanded_len(char *word, t_data *data);
char *remove_dollars_before_quote(char *str, t_data *data);
// ---------------------------------- Expand utils -------------------------------------------------
int skip_to_closing_brace(char *word);
int skip_to_end_of_variable(char *word);
int ft_strlen_variable_name_without_brace(char *word);
int ft_strlen_variable_name_with_brace(char *word);
void ft_strncpy_variable_name(char *dest, char *src, int len);
void increment(int *i, int *expanded_len);
// ------------------------------------- Utils -------------------------------------------------
char *skype_space_ptr(char *string);
void skype_space(char *str, int *i);
void free_old_node(t_tokens *node);
bool have_redirections(char *str, t_data *data);

#endif