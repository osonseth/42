
#include "test.h"
#include "string.h"

// int ft_strlen(char *str)
// {
//     int i;

//     if (str == NULL)
//         return (0);
//     i = 0;
//     while (str[i])
//     {
//         i++;
//     }

//     return (i);
// }
// void end_of_the_variable_name(char *str, int *i, int var)
// {

//     if (var == W_BRACE)
//     {
//         while (*str && *str != 125)
//         {
//             (*i)++;
//             str++;
//         }
//     }
//     else if (!is_alnum_or_underscore(str[1]))
//         return;
//     else
//     {
//         str++;

//         while (*str && is_alnum_or_underscore(*str))
//         {
//             (*i)++;
//             str++;
//         }
//     }
// }

// int strlen_variable_name(char *str, int var)
// {
//     int i;
//     i = 0;
//     if (var == W_BRACE)
//     {
//         while (str[i] && str[i] != 125)
//             i++;
//     }
//     else
//     {
//         while (str[i] && is_alnum_or_underscore(str[i]))
//             i++;
//     }

//     return i;
// }

// int calculate_expanded_words(char *str, int var, t_data *data)
// {
//     (void)data;
//     int variable_name_lenght;
//     variable_name_lenght = strlen_variable_name(str, var);
//     char *variable_name = malloc((1 + variable_name_lenght) * sizeof(char));
//     if (variable_name == NULL)
//         printf("error malloc");
//     variable_name[variable_name_lenght] = '\0';

//     int i;
//     i = 0;

//     if (var == W_BRACE)
//     {
//         while (str[i] && str[i] != 125)
//         {
//             variable_name[i] = str[i];
//             i++;
//         }
//     }
//     else
//     {
//         while (str[i] && is_alnum_or_underscore(str[i]))
//         {
//             variable_name[i] = str[i];
//             i++;
//         }
//     }

//     return (ft_strlen(getenv(variable_name)));
// }
// int calculate_expanded_lenght(t_data *data)
// {
//     int i;
//     int lenght;
//     i = 0;
//     lenght = 0;
//     char *str = data->table->simple_cmd;
//     while (str[i])
//     {
//         if (str[i] == '"' || str[i] == '\'')
//             check_quote(str[i], data);
//         if (str[i] == '$' && str[i + 1] == '{' && !data->simple_quote)
//         {
//             lenght += calculate_expanded_words(&str[i + 2], W_BRACE, data);
//             end_of_the_variable_name(&str[i], &i, W_BRACE);
//         }
//         else if (str[i] == '$' && !data->simple_quote)
//         {
//             lenght += calculate_expanded_words(&str[i + 1], WO_BRACE, data);
//             end_of_the_variable_name(&str[i], &i, WO_BRACE);
//             if (str[i] == '$')
//                 lenght++;
//         }

//         else
//             lenght++;
//         i++;
//     }
//     return lenght;
// }

int ft_strncmp(char *s1, char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
        i++;
    return (s1[i] - s2[i]);
}
bool is_space(char c)
{
    return (c == 9 || c == 32);
}
// char *skype_space_ptr(char *str)
// {
//     while (is_space(*str) && *str)
//         str++;
//     return str;
// }
void skype_space(char *str, int *i)
{
    while (is_space(*str) && *str)
    {
        (*i)++;
        str++;
    }
}

int ft_strlen_token(char *str)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i] && !is_space(str[i]))
    {
        i++;
    }
    return (i);
}
static void ft_strcpy_token(char *dst, char *src)
{
    size_t i;

    i = 0;
    while (src[i] && !is_space(src[i]))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char *ft_strdup_token(char *s)
{
    char *dest;

    dest = malloc(1 + ft_strlen_token(s) * sizeof(char));

    if (!dest)
        return (NULL);
    ft_strcpy_token(dest, s);
    return (dest);
}
int ft_strlen_token_double_quote(char *str)
{
    char *end;
    char *start;
    if (str == NULL)
        return (0);
    start = str;
    str++;

    while (*str && *str != '"')
    {
        str++;
    }
    end = str + 1;
    return (end - start);
}

static void ft_strcpy_token_double_quote(char *dst, char *src, int len)
{
    int i;

    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
}

char *ft_strdup_token_double_quote(char *s)
{
    char *dest;
    int len;
    len = ft_strlen_token_double_quote(s);
    dest = malloc(1 + len * sizeof(char));

    if (!dest)
        return (NULL);
    ft_strcpy_token_double_quote(dest, s, len);
    return (dest);
}

int ft_strlen_token_simple_quote(char *str)
{
    char *end;
    char *start;
    if (str == NULL)
        return (0);
    start = str;
    str++;
    while (*str && *str != '\'')
    {
        str++;
    }
    end = str + 1;
    return (end - start);
}
static void ft_strcpy_token_simple_quote(char *dst, char *src, int len)
{
    int i;

    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char *ft_strdup_token_simple_quote(char *s)
{
    char *dest;
    int len;
    len = ft_strlen_token_simple_quote(s);
    dest = malloc(1 + len * sizeof(char));

    if (!dest)
        return (NULL);
    ft_strcpy_token_simple_quote(dest, s, len);
    return (dest);
}
void create_token_double_quote(t_commands_table *table, t_data *data, int *i)
{
    char *line_start;

    line_start = &table->simple_cmd[*i];
    line_start = ft_strdup_token_double_quote(line_start);
    tokens_node_add_back(&(table->token), new_tokens_node(line_start), data);
    *i += ft_strlen_token_double_quote(line_start) - 1;
}
void create_token_simple_quote(t_commands_table *table, t_data *data, int *i)
{
    char *line_start;

    line_start = &table->simple_cmd[*i];
    line_start = ft_strdup_token_simple_quote(line_start);
    tokens_node_add_back(&(table->token), new_tokens_node(line_start), data);
    *i += ft_strlen_token_simple_quote(line_start) - 1;
}
void create_token_empty_quote(t_commands_table *table, t_data *data, int *i)
{
    char *line_start;

    line_start = malloc(1 * sizeof(char));
    line_start[0] = '\0';
    tokens_node_add_back(&(table->token), new_tokens_node(line_start), data);
    (*i)++;
}
void create_token(t_commands_table *table, t_data *data, int *i)
{
    char *line_start;

    line_start = &table->simple_cmd[*i];
    line_start = ft_strdup_token(line_start);
    tokens_node_add_back(&(table->token), new_tokens_node(line_start), data);
    *i += ft_strlen_token(line_start) - 1;
}

void node_tokenization(t_data *data, t_commands_table *table)
{
    int i;
    i = 0;

    while (table->simple_cmd[i])
    {
        skype_space(&table->simple_cmd[i], &i);
        if (table->simple_cmd[i] == '"' && table->simple_cmd[i + 1] != '"')
            create_token_double_quote(table, data, &i);
        else if (table->simple_cmd[i] == '\'' && table->simple_cmd[i + 1] != '\'')
            create_token_simple_quote(table, data, &i);
        else if (!ft_strncmp(&table->simple_cmd[i], "'' ", 3) || !ft_strncmp(&table->simple_cmd[i], "\"\" ", 3) || !ft_strncmp(&table->simple_cmd[i], "\"\"\0", 3) || !ft_strncmp(&table->simple_cmd[i], "''\0", 3))
            create_token_empty_quote(table, data, &i);
        else if (table->simple_cmd[i])
            create_token(table, data, &i);
        i++;
    }
}

int main()
{
    t_data(data) = {0};

    char *str = calloc(50, sizeof(char));
    strncpy(str, "echo '' ''  on'test'ok  ''encore''un test    ''", 50);
    printf("%s\n", str);
    data.table = new_cmd_table_node(str);
    node_tokenisation(&data, data.table);
    print_tokens(&data);

    return 0;
}