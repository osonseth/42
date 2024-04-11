/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 02:10:15 by max               #+#    #+#             */
/*   Updated: 2024/04/11 03:03:09 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

void ft_bzero_solong(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = '\0';
        i++;
    }
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *p;

    if (nmemb == 0 || size == 0)
        return (malloc(0));
    if (nmemb > INT_MAX / size)
        return (NULL);
    p = malloc(nmemb * size * sizeof(char));
    if (!p)
        return (NULL);
    ft_bzero_solong(p, nmemb * size);
    return (p);
}

int ft_count_words(char *str, char c)
{
    bool new_word;
    int count_words;

    new_word = false;
    count_words = 0;
    if (str)
    {
        while (*str)
        {
            if (*str != c && new_word == false)
            {
                new_word = true;
                count_words++;
            }
            else if (*str == c)
            {
                new_word = false;
            }
            str++;
        }
    }

    return (count_words);
}

int ft_strlen_split(char const *s, char c)
{
    int len;

    len = 0;
    while (*s != c && *s != '\0')
    {
        len++;
        s++;
    }
    return (len);
}

void ft_strcpy_split(char *dst, const char *src, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char **ft_split(char const *s, char c)
{
    char **tab;
    int words;
    int i;
    bool new_words;

    i = 0;
    new_words = false;
    words = ft_count_words((char *)s, c);
    tab = ft_calloc(words, sizeof(char *));
    if (!tab)
        return (NULL);
    while (*s)
    {
        if (*s != c && new_words == false)
        {
            new_words = true;
            tab[i] = malloc(1 + ft_strlen_split(s, c) * sizeof(char));
            ft_strcpy_split(tab[i], s, ft_strlen_split(s, c));
            i++;
        }
        else if (*s == c && new_words == true)
            new_words = false;
        s++;
    }
    return (tab);
}
