/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:37:57 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/09 14:54:58 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0 || nmemb > INT_MAX / size)
		return (NULL);
	p = malloc(nmemb * size * sizeof(char));
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
