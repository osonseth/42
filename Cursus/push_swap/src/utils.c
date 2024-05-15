/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:29:16 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 17:24:56 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strcpy(char *dest, char *src1, char *src2)
{
	int	i;

	i = 0;
	if (src1)
	{
		while (src1[i])
		{
			dest[i] = src1[i];
			i++;
		}
	}
	dest[i] = ' ';
	i++;
	while (*src2)
	{
		dest[i] = *src2;
		i++;
		src2++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strjoin_push_swap(t_data *data, int i)
{
	int		len1;
	int		len2;
	char	*str;

	str = data->join_argv;
	len1 = ft_strlen(data->join_argv);
	len2 = ft_strlen(data->argv[i]);
	data->join_argv = malloc(2 + len1 + len2);
	if (data->join_argv == NULL)
	{
		if (str)
			free(str);
		display_error();
	}
	data->join_argv = ft_strcpy(data->join_argv, str, data->argv[i]);
	free(str);
}

int	ft_abs_ps(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
