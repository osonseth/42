/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:01:35 by max               #+#    #+#             */
/*   Updated: 2024/04/11 19:32:28 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map_name(char *argument)
{
    int i;

    i = 0;

    while (argument[i])
        i++;

    if (ft_strncmp(".ber", &argument[i - 4], 4))
    {
        ft_printf("Error\nInvalid map name\n");
        exit(EXIT_FAILURE);
    }
}

// lis le fichier .ber ligne par ligne et le concatène dans une seule string
char *read_map(char *map)
{
    int fd;
    char *tmp;
    char *str;
    str = NULL;

    fd = open(map, O_RDONLY);

    if (fd == -1)
    {
        perror("Error\nOpening file");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        tmp = get_next_line(fd);
        if (tmp == NULL)
            break;
        str = ft_strjoin_solong(str, tmp);
        free(tmp);
        tmp = NULL;
    }
    close(fd);
    if (str == NULL)
        display_error("Error\nEmpty map");
    return str;
}

void check_map_constraints(t_data *data)
{
    check_map_is_rectangle(data);
    
}
