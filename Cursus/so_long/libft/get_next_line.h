/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:45 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/30 14:12:38 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		gnl_strlen(char *str);
int		gnl_strchr(char *str, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*concatenate_strings(char *dest, char *s1, char *s2);
char	*get_next_line(int fd);

#endif
