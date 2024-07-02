/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:32 by max               #+#    #+#             */
/*   Updated: 2024/06/27 08:48:42 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_table(t_data *data)
{
	t_commands_table	*current;

	current = data->table;
	if (current == NULL)
		printf("liste vide\n");
	while (current)
	{
		printf("%s\n", current->simple_cmd);
		current = current->next;
	}
}