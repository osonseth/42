/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:22:50 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/02 00:25:20 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_arguments(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->argc)
	{
		if (data->argv[i][0] == '\0')
			error(data);
		ft_strjoin_push_swap(data, i);
		i++;
	}
}

void	parsing_management(t_data *data)
{
	join_arguments(data);
	check_char(data);
}
