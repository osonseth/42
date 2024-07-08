#include "test.h"

// int number_of_expand(t_data *data)
// {
//     char *str = data->table->simple_cmd;
//     int nbr = 0;

//     while (*str)
//     {
//         if (*str == '"' || *str == '\'')
//             quote_syntax_errors(*str, data);
//         if (*str == '$' && str[1] == '{' && !data->simple_quote)
//             nbr++;
//         else if (*str == '$' && !data->simple_quote && is_alnum_or_underscore(str[1]))
//             nbr++;
        
//         str++;
//     }
//     return nbr;
// }

void opening_and_closing_quotes(char c, t_data *data)
{

    if (c == '"' && data->simple_quote == false)
    {
        if (data->double_quote == false)
            data->double_quote = true;
        else
            data->double_quote = false;
    }
    else if (c == '\'' && data->double_quote == false)
    {
        if (data->simple_quote == false)
            data->simple_quote = true;
        else
            data->simple_quote = false;
    }
}
