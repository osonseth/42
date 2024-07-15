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

#define ENV_PATH "PATH=/home/max/.local/bin:/home/max/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin"
#define ENV_USER "USER=max"
#define ENV_HOME "HOME=/home/max"
#define ENV_PWD "PWD=/home/max/minishell"

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
    char **shell_env;

} t_data;

void opening_and_closing_quotes(char c, t_data *data);

#endif