
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
//         while (*str && *str != CLOSING_BRACE)
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
//         while (str[i] && str[i] != CLOSING_BRACE)
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
//         while (str[i] && str[i] != CLOSING_BRACE)
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
//             quote_syntax_errors(str[i], data);
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



// char *skype_space_ptr(char *str)
// {
//     while (is_space(*str) && *str)
//         str++;
//     return str;
// }





















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