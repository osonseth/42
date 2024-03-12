/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:31 by mmauchre          #+#    #+#             */
/*   Updated: 2024/02/17 14:47:48 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

char	*get_next_line(int fd);
char	*ft_line(char *str);
bool	check_eol(char *str);
int		ft_strlen(char *str);
int		ft_strlen_of_line(char *str);
char	*ft_strjoin(char *buffer, char *stash);
void	ft_bzero(void *s, int n);
char	*ft_clean_stash(char *str);
char	*make_line(char **line, char **stash);

#endif