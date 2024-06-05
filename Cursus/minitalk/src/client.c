/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:10:47 by max               #+#    #+#             */
/*   Updated: 2024/06/04 23:49:52 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile bool g_receveived = true;

int ft_atoi(char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

void handle(int sig)
{
	if (sig == SIGUSR1)
		g_receveived = true;
}

void send_char(int pid, char c)
{
	int i;
	i = 7;

	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("Error kill\n");
				exit(EXIT_FAILURE);
			}
			g_receveived = false;
		}

		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("Error kill\n");
				exit(EXIT_FAILURE);
			}
			g_receveived = false;
		}
		if (g_receveived == false)
		{

			pause();
			g_receveived = true;
		}

		i--;
	}
}

void send_str(int pid, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int main(int argc, char **argv)
{
	int pid;
	char *str;

	if (argc == 3)
	{
		if (signal(SIGUSR1, handle) == SIG_ERR)
		{
			printf("Error setting signal handler");
			exit(EXIT_FAILURE);
		}
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_str(pid, str);
	}
	else
	{
		write(1, "invalid number of arguments\n", 23);
		return (1);
	}
}
