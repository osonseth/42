/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:52:24 by mmauchre          #+#    #+#             */
/*   Updated: 2023/09/25 13:02:34 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
