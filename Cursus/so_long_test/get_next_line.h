/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:20:07 by mmauchre          #+#    #+#             */
/*   Updated: 2024/04/11 18:17:25 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *ft_line(char *str);
bool check_eol(char *str);
int ft_strlen(char *str);
int ft_strlen_of_line(char *str);
char *ft_strjoin(char *buffer, char *stash);
void ft_bzero(void *s, size_t n);
char *ft_clean_stash(char *str);
char *make_line(char **line, char **stash);

#endif