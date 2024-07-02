/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:13 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/11 02:37:26 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(char **line, char **stash)
{
	*line = ft_line(*stash);
	*stash = ft_clean_stash(*stash);
	return (*line);
}

char	*ft_clean_stash(char *str)
{
	char	*new_stash;
	int		len;

	int (i) = 0;
	len = ft_strlen_of_line(str);
	new_stash = malloc((ft_strlen(&str[len]) + 1) * sizeof(char));
	while (str[len + i])
	{
		new_stash[i] = str[len + i];
		i++;
	}
	new_stash[i] = '\0';
	free(str);
	return (new_stash);
}

char	*ft_line(char *str)
{
	char *(line) = malloc((ft_strlen_of_line(str) + 1) * sizeof(char));
	int (i) = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
	{
		line[i] = '\0';
		return (line);
	}
	else if (str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	return (line);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	int (i) = 0;
	int (j) = 0;
	int (total_len) = ft_strlen(buffer) + ft_strlen(stash);
	char *(str) = malloc((1 + total_len) * sizeof(char));
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
	char (buffer)[BUFFER_SIZE + 1] = {0};
	static char *(stash)[1024] = {0};
	char *(line) = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd] && check_eol(stash[fd]))
		return (make_line(&line, &stash[fd]));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		stash[fd] = ft_strjoin(buffer, stash[fd]);
		if (check_eol(stash[fd]))
			return (make_line(&line, &stash[fd]));
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (stash[fd])
	{
		if (stash[fd][0] == '\0')
			return (free(stash[fd]), NULL);
		line = ft_line(stash[fd]);
		free(stash[fd]);
		stash[fd] = NULL;
		return (line);
	}
	return (NULL);
}
