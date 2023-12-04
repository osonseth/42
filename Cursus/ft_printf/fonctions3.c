/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by mmauchre          #+#    #+#             */
/*   Updated: 2023/12/04 19:04:20 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	check_flag(char c)
{
	if (c == 'd' || c == 's' || c == 'c' || c == 'u' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'p' || c == 'c')
		return (true);
	return (false);
}

int	check_bonus(char c)
{
	if (c == '+' || c == ' ' || c == '#' || c == '0' || c == '.' || c == '-')
		return (true);
	return (false);
}
