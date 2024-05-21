/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:13:49 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/15 21:15:16 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_above_median(t_list **lst1, t_list **lst2)
{
	int	min;

	if ((*lst1)->index <= (*lst2)->index)
		min = (*lst1)->index;
	else
		min = (*lst2)->index;
	(*lst1)->cost = (*lst1)->index + (*lst2)->index - min;
}

void	two_below_median(t_list **lst1, t_list **lst2, t_data *data)
{
	int	min;

	if (data->len_a - (*lst1)->index <= data->len_b - (*lst2)->index)
		min = data->len_a - (*lst1)->index;
	else
		min = data->len_b - (*lst2)->index;
	(*lst1)->cost = (data->len_a - (*lst1)->index) + (data->len_b
			- (*lst2)->index) - min;
}
