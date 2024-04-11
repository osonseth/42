/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:41:19 by max               #+#    #+#             */
/*   Updated: 2024/04/12 00:49:56 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clear_array_split(char **array, int j)
{
    int i;
    i = 0;

    while (i < j)
    {
        if (array[i])
            free(array[i]);
        i++;
    }
    free(array);

        perror("Error\nMemory allocation error");
        exit(EXIT_FAILURE);
}

void clear_array(char **array, int j)
{
    int i;
    i = 0;

    while (i < j)
    {
        if (array[i])
            free(array[i]);
        i++;
    }
    free(array);
}

