/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:16:46 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/06 10:17:55 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	check_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i])
		{
			if (check_char(argv[1][i], argv[1]) || check_char(argv[1][i],
					argv[2]))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (check_char(argv[2][i], argv[1]) || check_char(argv[2][i],
					argv[2]))
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
