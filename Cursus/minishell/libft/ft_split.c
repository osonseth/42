/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:29:12 by max               #+#    #+#             */
/*   Updated: 2024/07/21 23:39:36 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void clean_split(char **array, int j)
{
    int i;

    i = 0;
    while (i < j)
    {
        if (array[i])
        {
            free(array[i]);
            array[i] = NULL;
        }
        i++;
    }
    free(array);
    array = NULL;
}

static int count_words(char *str)
{
    int words;
    bool new_words;

    new_words = false;
    words = 0;
    while (*str)
    {
        if (*str != ':' && new_words == false)
        {
            words++;
            new_words = true;
        }
        if (*str == ':')
            new_words = false;
        str++;
    }
    return (words);
}
static int strlen_split(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != ':' && str[i] != '\0')
    {
        i++;
    }
    return (i);
}

static char *strcpy_split(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != ':' && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
char **ft_split(char *str)
{
    char **array;
    int words;

    int(i) = 0;
    words = count_words(str);
    array = malloc((words + 1) * sizeof(char *));
    if (array == NULL)
        return (NULL);
    while (i < words)
    {
        while (*str == ':' && *str != '\0')
            str++;
        array[i] = malloc((1 + strlen_split(str)) * sizeof(char));
        if (array[i] == NULL)
        {
            clean_split(array, i);
            return (NULL);
        }
        strcpy_split(array[i], str);
        while (*str != ':' && *str != '\0')
            str++;
        i++;
    }
    array[i] = NULL;
    return (array);
}
