/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:13 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/10 03:49:19 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *str)
{
	char	*new_stash;
	int		len;

	len = ft_strlen_of_line(str);
	new_stash = ft_strdup(&str[len + 1]);
	free(str);
	return (new_stash);
}

char	*ft_line(char *str)
{
	char *(line) = malloc((ft_strlen_of_line(str) + 2) * sizeof(char));
	int(i) = 0;
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
		line[i++] = '\n';
		line[i] = '\0';
	}
	return (line);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	int(i) = 0;
	int(j) = 0;
	int(total_len) = ft_strlen(buffer) + ft_strlen(stash);
	char *(str) = malloc((1 + total_len) * sizeof(char));
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buffer[j])
	{
		str[i] = buffer[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];

	static char *(stash) = NULL;
	char *(line) = NULL;
	if (stash)
	{
		if (check_eol(stash))
		{
			line = ft_line(stash);
			stash = ft_clean_stash(stash);
			return (line);
		}
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin(buffer, stash);
		if (check_eol(stash))
		{
			line = ft_line(stash);
			stash = ft_clean_stash(stash);
			return (line);
		}
	}
	if (stash)
	{
		line = ft_line(stash);
		stash = NULL;
		return (line);
	}
	return (NULL);
}

int	main(void)
{
	int fd;
	char *line;
	int i;
	int trigger;

	fd = open("test.txt", O_RDONLY);
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