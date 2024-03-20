/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:31 by mmauchre          #+#    #+#             */
/*   Updated: 2024/03/20 15:49:53 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_data
{
	int				fd;
	unsigned int	number_of_line;
	char			**map;

}					t_data;

typedef struct s_list
{
	char			*line_of_map;
	struct s_list	*next;
}					t_list;

bool				list_is_empty(t_list *list);
int					list_length(t_list *list);
void				print_list(t_list *list);
t_list				*make_list(t_data *data, t_list *map);
t_list				*insert_back_list(t_list *list, char *line);
t_list				*cut_front_list(t_list *map);
t_list				*cut_back_list(t_list *map);
t_list				*remove_front_list(t_list *list);
t_list				*clear_list(t_list *list);
t_list				*manage(t_data *data, t_list *map);

#endif