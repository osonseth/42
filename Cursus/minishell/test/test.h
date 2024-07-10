#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W_BRACE 0
#define WO_BRACE 1
#define EMPTY_QUOTE 2
#define IN_DOUBLE_QUOTE 3
#define IN_SIMPLE_QUOTE 4


typedef struct s_tokens
{
    char *word;
    struct s_tokens *next;

} t_tokens;

typedef struct s_commands_table
{
    char *simple_cmd;
    char **args;
    t_tokens *token;
    struct s_commands_table *next;

} t_commands_table;

typedef struct data
{
    t_commands_table *table;
    char *line;
    bool simple_quote;
    bool double_quote;

} t_data;

t_commands_table *new_cmd_table_node(void *content);
t_tokens *new_tokens_node(void *content);
void tokens_node_add_back(t_tokens **lst, t_tokens *new, t_data *data);

void opening_and_closing_quotes(char c, t_data *data);
void print_tokens(t_data *data);

#endif