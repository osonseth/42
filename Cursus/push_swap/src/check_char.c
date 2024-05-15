/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:09:58 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 13:09:53 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
}

static bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

static bool	is_digit(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	is_digit_sign_space(char c)
{
	if (is_sign(c) || is_space(c) || is_digit("0123456789", c))
	{
		return (true);
	}
	return (false);
}

void	check_char(t_data *data)
{
	int	i;

	i = 1;
	while (data->join_argv[i])
	{
		if (!is_digit_sign_space(data->join_argv[i]))
			error(data);
		if (is_sign(data->join_argv[i]) && is_sign(data->join_argv[i - 1]))
			error(data);
		if (is_sign(data->join_argv[i]) && !is_space(data->join_argv[i - 1]))
			error(data);
		if (is_space(data->join_argv[i]) && is_sign(data->join_argv[i - 1]))
			error(data);
		if (is_sign(data->join_argv[i]) && data->join_argv[i + 1] == '\0')
			error(data);
		i++;
	}
}
