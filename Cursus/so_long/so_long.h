/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:31 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/14 20:32:10 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int		count_line;
	int		fd;
	char	**map;
}			t_data;

void		ft_count_line(t_data *data);
void		open_map(t_data *data);

#endif