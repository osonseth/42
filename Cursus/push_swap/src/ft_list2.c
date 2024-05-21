/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:31:51 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 17:34:56 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_list **lst)
{
	int		len;
	t_list	*current;

	current = *lst;
	len = 0;
	while (current != NULL)
	{
		current->index = len;
		current->is_cheaper = false;
		len++;
		current = current->next;
	}
	return (len);
}
