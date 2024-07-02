/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:10:47 by max               #+#    #+#             */
/*   Updated: 2024/06/07 16:10:58 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_receveived = true;

int	ft_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

void	handle(int sig)
{
	if (sig == SIGUSR1)
		g_receveived = true;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			g_receveived = false;
			if (kill(pid, SIGUSR1) == -1)
				error_kill();
		}
		else
		{
			g_receveived = false;
			if (kill(pid, SIGUSR2) == -1)
				error_kill();
		}
		while (g_receveived == false)
			usleep(10000);
		i--;
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (!argv[2][0])
			return (1);
		if (signal(SIGUSR1, handle) == SIG_ERR)
		{
			write(1, "Error setting signal handler\n", 28);
			exit(EXIT_FAILURE);
		}
		pid = ft_atoi(argv[1]);
		if (pid < 1)
		{
			write(1, "Invalid PID\n", 12);
			exit(EXIT_FAILURE);
		}
		send_str(pid, argv[2]);
	}
	else
	{
		write(1, "invalid number of arguments\n", 23);
		return (1);
	}
}
