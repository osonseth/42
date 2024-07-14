
#include "test.h"
#include "string.h"

char *remove_dollars_before_quote(char *str, t_data *data)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (str[i])
    {
        opening_and_closing_quotes(str[i], data);
        if ((!strncmp(&str[i], "$\"", 2) || !strncmp(&str[i], "$'", 2)) && !data->simple_quote & !data->double_quote)
        {
            i++;
            continue;
        }
        else
        {
            str[j++] = str[i++];
        }
    }
    while (str[j])
    {
        str[j] = '\0';
        j++;
    }
    return str;
}

int main()
{
    t_data(data) = {0};

    char *str = calloc(50, sizeof(char));
    strncpy(str, "echo $\"USER\"   '${USER}' $'USER ", 50);
    printf("avant : %s\n", str);
    str = remove_dollars(str, &data);
    printf("apres : %s\n", str);

    return 0;
}
