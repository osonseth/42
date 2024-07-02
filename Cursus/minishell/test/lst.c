#include "test.h"

t_commands_table *new_cmd_table_node(void *content)
{
    t_commands_table *node;

    node = malloc(sizeof(t_commands_table));
    if (node == NULL)
        return NULL;
    node->simple_cmd = content;
    node->next = NULL;
    node->args = NULL;
    
    return (node);
}