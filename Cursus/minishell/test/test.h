#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W_BRACE 0
#define WO_BRACE 1

typedef struct s_commands_table
{
    char *simple_cmd;
    char **args;
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
void check_quote(char c, t_data *data);
void check_close_quote(t_data *data);
int number_of_expand (t_data *data);
bool is_alnum_or_underscore(char c);

#endif