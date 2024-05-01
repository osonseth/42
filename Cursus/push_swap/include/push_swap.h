/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:43 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/01 23:11:23 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_data
{
	char	**argv;
	int		argc;
	char	*join_argv;
}			t_data;

//----------------------------------------------
void		parsing_management(t_data *data);
void		ft_strjoin_push_swap(t_data *data, int i);
void		join_arguments(t_data *data);
void		check_char(t_data *data);
void		clean_all(t_data *data);
void		display_error(void);

//----------------------------------------------

void		clean_all_tmp(t_data *data);

#endif
