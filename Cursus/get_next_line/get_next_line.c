/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:57:39 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/22 10:48:05 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*clean_backup_stash(char *backup_stash, char *stash)
{
	int(i) = 0;
	stash = malloc((ft_strlen(backup_stash) + 1) * sizeof(char));
	while (backup_stash[i])
	{
		stash[i] = backup_stash[i];
		i++;
	}
	free(backup_stash);
	backup_stash = NULL;
	return (stash);
}

char	*finded_eol(char *line, char *stash, char *backup_stash)
{
	int(i) = 0;
	line = malloc((ft_len_line(stash) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	backup_stash = malloc((ft_strlen(stash) + 1) * sizeof(char));
	while (stash[i])
	{
		*backup_stash = stash[i];
		printf("%c\n",*backup_stash);
		i++;
		backup_stash++;
	}
	free(stash);
	stash = NULL;
	return (line);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	char *(str) = NULL;
	int(i) = 0;
	int(j) = 0;
	int(total_len) = ft_strlen(buffer) + ft_strlen(stash);
	str = malloc((1 + total_len) * sizeof(char));
	if (!str)
		return (NULL);
	if (stash)
	{
		while (stash[i])
		{
			str[i] = stash[i];
			i++;
		}
	}
	while (buffer[j])
	{
		str[i] = buffer[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(stash);
	stash = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];

	char *(stash) = NULL;
	char *(line) = NULL;
	static char *(backup_stash) = NULL;
	int(end_of_file) = 1;
	if (backup_stash)
		clean_backup_stash(backup_stash, stash);
	while (end_of_file > 0)
	{
		end_of_file = read(fd, buffer, sizeof(buffer) - 1);
		buffer[BUFFER_SIZE + 1] = '\0';
		stash = ft_strjoin(buffer, stash);
		if (check_eol(stash))
		{
			line = finded_eol(line, stash, backup_stash);
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}