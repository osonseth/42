/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:13 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/10 23:38:41 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *str)
{
	char	*new_stash;
	int		len;

	int(i) = 0;
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
		line[i] = '\n';
		line[i + 1] = '\0';
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
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	int	i;

	char(buffer)[BUFFER_SIZE + 1] = {0};
	static char *(stash) = NULL;
	char *(line) = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash && check_eol(stash))
	{
		line = ft_line(stash);
		stash = ft_clean_stash(stash);
		return (line);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
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
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
	}
	if (stash)
	{
		if (stash[0] == '\0')
		{
			free(stash);
			return (NULL);
		}
		line = ft_line(stash);
		free(stash);
		stash = NULL;
		return (line);
	}
	return (NULL);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int i = 0;
// 	// int trigger;

// fd = open("test.txt", O_RDONLY);

// while ( i < 2)
// {
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	// if (line == NULL)
// 	// 	break ;
// 	i++;
// 	free(line);
// }
// trigger = 1;
// printf("\033[36;01m| vv | le texte demarre a la ligne d'en dessou en blanc | vv |\033[00m\n");
// while (trigger == 1)
// {
// 	line = get_next_line(fd);
// 	printf("\033[36;01m| %2d |\033[00m%s\033[36;01m|\033[00m\n", i, line);
// 	if (line == NULL)
// 		trigger = 0;
// 	free(line);
// 	i++;
// }
// printf("\033[36;01m| ^^ | le texte prend fin a la ligne du dessus en blanc | ^^ |\033[00m\n");
// 	return (0);
// }