/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:47 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/01 20:30:39 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_management(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->argc)
	{
		if (data->argv[i][0] == '\0')
			clean_all(data);
		ft_strjoin_push_swap(data, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	t_data(data) = {0};
	data.argc = argc;
	data.argv = argv;
	parsing_management(&data);
	clean_all(&data);
	return (0);
}
