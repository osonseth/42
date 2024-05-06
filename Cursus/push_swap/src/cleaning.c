/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:24:15 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 08:08:56 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	clean_array_number(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->array_number_height)
	{
		free(data->array_number[i]);
		data->array_number[i] = NULL;
		i++;
	}
	free(data->array_number);
	data->array_number = NULL;
}

void	clean_parsing(t_data *data)
{
	if (data->join_argv)
	{
		free(data->join_argv);
		data->join_argv = NULL;
	}
	if (data->array_number)
		clean_array_number(data);
}

void	error(t_data *data)
{
	clean_parsing(data);
	display_error();
}
