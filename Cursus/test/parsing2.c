/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:20:36 by max               #+#    #+#             */
/*   Updated: 2024/04/14 07:51:02 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    ft_bzero(p, nmemb * size);
    return (p);
}

// fonction strncmp basique
int ft_strncmp(char *s1, char *s2, int n)
{
    if (n == 0)
        return (0);
    while (*s1 && n - 1 > 0)
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        s1++;
        s2++;
        n--;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*copie la src dans la dest uniquement si src != NULL car
dans le premier appel src == NULL (segfault)*/
char *ft_strcpy(char *dest, const char *src)
{
    int i = 0;
    if (src)
    {
        while (src[i])
        {
            dest[i] = src[i];
            i++;
        }
    }

    dest[i] = '\0';
    return dest;
}
/* malloc une string de la taille des 2 reçues en paramètres puis les
 envoie a ft_strcpy, free S1 si non NULL car le premier appel de la
 fonction aura s1 == NULL, renvoie ensuite la string*/

char *ft_strjoin_solong(char *s1, char *s2)
{

    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *str = malloc(1 + len1 + len2);
    if (!str)
        return NULL;

    ft_strcpy(str, s1);

    ft_strcpy(str + len1, s2);

    if (s1)
        free(s1);
    return str;
}
// affiche la string en paramètre et exit (EXIT_FAILURE)
void display_error(char *str)
{

    ft_printf("%s\n", str);
    exit(EXIT_FAILURE);
}