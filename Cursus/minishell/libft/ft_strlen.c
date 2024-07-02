/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:48:12 by mmauchre          #+#    #+#             */
/*   Updated: 2024/06/26 11:08:03 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_strlen_simple_cmd(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '|')
	{
		i++;
	}
	return (i);
}

int ft_strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
