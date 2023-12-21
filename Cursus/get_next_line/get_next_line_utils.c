/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:57:42 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/22 00:37:42 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	check_eol(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (true);
	}
	return (false);
}

int	ft_len_line(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}