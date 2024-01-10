/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:07 by mmauchre          #+#    #+#             */
/*   Updated: 2024/01/10 23:55:30 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_line(char *str);
bool	check_eol(char *str);
int		ft_strlen(char *str);
int		ft_strlen_of_line(char *str);
char	*ft_strdup(char *s);
void	ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *buffer, char *stash);
void	ft_bzero(void *s, int n);


#endif