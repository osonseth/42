/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:38:02 by max               #+#    #+#             */
/*   Updated: 2024/04/03 10:28:07 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// calcul la longueur d'une lignes de la map
int ft_strlen_so_long(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
    {
        i++;
    }
    return (i);
}

void check_argument(char *argument)
{
    int i;

    i = 0;

    while (argument[i])
        i++;

    printf ("%s\n",&argument[i-4]);
    if (ft_strncmp(".ber", &argument[i - 4], 4))
    {
        printf("Error\ninvalid name of map\n");
        exit(EXIT_FAILURE);
    }
}
