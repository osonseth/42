/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:06:31 by max               #+#    #+#             */
/*   Updated: 2024/06/05 16:11:31 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

int count_digit(int n)
{
	int digit;

	digit = 0;
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char *ft_itoa(int n, char *s)
{
	int len;

	len = count_digit(n);
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}
void handle(int sig, siginfo_t *info, void *context)
{
	(void)context;
	static char byte = 0;
	static int bit_count = 0;

	if (sig == SIGUSR1)
		byte = (byte << 1) | 1;
	else
		byte <<= 1;
	bit_count++;

	if (bit_count == 8)
	{
		if (byte == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &byte, sizeof(byte));

		byte = 0;
		bit_count = 0;
	}
	usleep(100);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		printf("Error kill\n");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	char pid[8];

	printf("PID : %s\n\n", ft_itoa(getpid(), pid));
	struct sigaction sa;

	ft_memset(&sa, 0, sizeof(sa));

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Error sigaction\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		pause();
	}
}

// for i in {1..50}; do ./client 4453 "azertyuiopqsdfghjklmwxcvbn"; done

