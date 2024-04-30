/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:21:02 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/30 10:21:05 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line_from_start(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(1 + i);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*allocate_and_copy_remaining(char *buffer, int length)
{
	int		j;
	char	*new_buffer;

	j = 0;
	new_buffer = (char *)malloc(1 + gnl_strlen(buffer) - length);
	if (!new_buffer)
		return (NULL);
	while (buffer[length + j])
	{
		new_buffer[j] = buffer[length + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*move_start_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (allocate_and_copy_remaining(buffer, i + 1));
}

char	*get_next_line(int fd)
{
	int			read_result;
	char		*temp_buffer;
	static char	*start_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_result = 1;
	temp_buffer = (char *)malloc(1 + BUFFER_SIZE);
	if (!temp_buffer)
		return (NULL);
	while (!(gnl_strchr(start_buffer, '\n')) && read_result != 0)
	{
		read_result = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[read_result] = '\0';
		start_buffer = gnl_strjoin(start_buffer, temp_buffer);
	}
	free(temp_buffer);
	temp_buffer = read_line_from_start(start_buffer);
	start_buffer = move_start_buffer(start_buffer);
	return (temp_buffer);
}
/*
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERREUR: Le fichier n'a pas pu etre ouvert\n");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/

/* MAIN TEST (ARGC, ARGV)

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <tests.txt>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERREUR: Le fichier %s n'a pas pu être ouvert\n", argv[1]);
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
