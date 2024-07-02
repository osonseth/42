#include "test.h"

int number_of_expand(t_data *data)
{
    char *str = data->table->simple_cmd;
    int nbr = 0;

    while (*str)
    {
        if (*str == '"' || *str == '\'')
            check_quote(*str, data);
        if (*str == '$' && str[1] == '{' && !data->simple_quote)
            nbr++;
        else if (*str == '$' && !data->simple_quote && is_alnum_or_underscore(str[1]))
            nbr++;
        
        str++;
    }
    return nbr;
}
