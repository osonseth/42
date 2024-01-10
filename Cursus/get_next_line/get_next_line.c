/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:57:39 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/10 00:40:18 by mmauchre         ###   ########.fr       */
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
	int(j) = 0;
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
	backup_stash = malloc((ft_strlen(&stash[i]) + 1) * sizeof(char));
	while (stash[i])
	{
		backup_stash[j] = stash[i];
		i++;
		j++;
	}
	backup_stash[j] = '\0';
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
	return (str);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*backup_stash;

	char *(stash) = NULL;
	char *(line) = NULL;
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
			if (backup_stash)
				printf("%s\n", backup_stash);
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		trigger;

	fd = open("txt/1char.txt", O_RDONLY);
	i = 0;
	trigger = 1;
	printf("\033[36;01m| vv | le texte demarre a la ligne d'en dessou en blanc | vv |\033[00m\n");
	while (trigger == 1)
	{
		line = get_next_line(fd);
		printf("\033[36;01m| %2d |\033[00m%s\033[36;01m|\033[00m\n", i, line);
		if (line == NULL)
			trigger = 0;
		free(line);
		i++;
	}
	printf("\033[36;01m| ^^ | le texte prend fin a la ligne du dessus en blanc | ^^ |\033[00m\n");
	return (0);
}