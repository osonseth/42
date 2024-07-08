/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:20:32 by max               #+#    #+#             */
/*   Updated: 2024/07/06 09:56:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool is_space(char c)
{
    return (c == 9 || c == 32);
}

bool ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool ft_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}
bool is_alnum_or_underscore(char c)
{
    return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}
bool is_alpha_or_underscore(char c)
{
    return (ft_isalpha(c) || c == '_');
}