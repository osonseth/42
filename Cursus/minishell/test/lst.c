#include "test.h"

t_commands_table *new_cmd_table_node(void *content)
{
    t_commands_table *node;

    node = malloc(sizeof(t_commands_table));
    if (node == NULL)
        return NULL;
    node->simple_cmd = content;
    node->token = NULL;
    node->next = NULL;
    node->args = NULL;

    return (node);
}
void tokens_node_add_back(t_tokens **lst, t_tokens *new, t_data *data)
{
    // supprimer le void
    (void)data;
    t_tokens *tmp;
    // if (new == NULL)
    //     memory_error(data);
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

t_tokens *new_tokens_node(void *content)
{
    t_tokens *node;

    node = malloc(sizeof(t_commands_table));
    if (node == NULL)
        return NULL;
    node->word = content;

    return (node);
}
// void print_tokens(t_data *data)
// {
// 	t_commands_table *current_table = data->table;

// 	while (current_table)
// 	{
// 		t_tokens *current_token = current_table->token;
// 		if (current_token == NULL)
// 		{
// 			printf("liste vide\n");
// 		}
// 		else
// 		{
// 			while (current_token)
// 			{
// 				printf("Token: %s\n", current_token->word);
// 				current_token = current_token->next;
// 			}
// 		}
// 		current_table = current_table->next;
// 	}
// }
void print_tokens(t_data *data)
{
    t_commands_table *current_table = data->table;
    t_tokens *current_token = current_table->token;

    while (current_token)
    {
        printf("Token:%s\n", current_token->word);
        current_token = current_token->next;
    }
}
