/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:24:15 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/01 23:22:07 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//--------------------------------------------------------
void	clean_all_tmp(t_data *data)
{
	if (data->join_argv)
		free(data->join_argv);
}

void	clean_all(t_data *data)
{
	if (data->join_argv)
		free(data->join_argv);
	display_error();
}
