/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:57:54 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/22 00:26:26 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*finded_eol(char *line, char *stash, char *backup_stash);
char	*clean_backup_stash(char *backup_stash, char *stash);
int		ft_strlen(char *str);
bool	check_eol(char *str);
int		ft_len_line(char *str);

#endif