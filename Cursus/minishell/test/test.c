
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

bool ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool ft_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}
bool is_alnum_or_underscore(char c)
{
    return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

bool is_alpha_or_underscore(char c)
{
    return (ft_isalpha(c) || c == '_');
}

static int ft_strncmp(char *s1, char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
        i++;
    return (s1[i] - s2[i]);
}
bool brace_not_closed_or_bad_syntax(char *str)
{
    while (*str)
    {
        if (!is_alnum_or_underscore(*str) && *str != 125)
            return true;
        if (*str == 125)
            return false;
        str++;
    }
    return true;
}


bool check_expand_syntax_error(char *str, t_data *data)
{
    while (*str)
    {
        opening_and_closing_quotes(*str, data);
        if (*str == '$' && !data->simple_quote)
        {
            if (!ft_strncmp(str, "${", 2))
            {
                if (!is_alpha_or_underscore(str[2]) || brace_not_closed_or_bad_syntax(str + 2))
                {
                    printf("Minishell: Bad substitution (Empty brace, brace not closed or bad syntaxe)\n");
                    return true;
                }
            }
            else if (!is_alnum_or_underscore(str[1]) && str[1] != 9 && str[1] != 32)
            {
                printf("Minishell: Bad substitution (Empty brace, brace not closed or bad syntaxe)\n");
                return true;
            }
        }
        str++;
    }
    return false;
}

int main()
{
    t_data(data) = {0};

    char *str = calloc(50, sizeof(char));
    strncpy(str, "echo ${   } | echo $_USER", 50);
    data.table = new_cmd_table_node(str);
    bool syntax = check_expand_syntax_error(str,&data);
    if (syntax)
        printf("Mauvaise syntaxe\n");
    else
        printf("Bonne syntaxe\n");

    return 0;
}