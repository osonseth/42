/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:43 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/03 16:31:48 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char			**argv;
	int				argc;
	int				array_number_height;
	char			*join_argv;
	char			**array_number;
}					t_data;

typedef struct s_list
{
	int				value;
	int				number_of_value;
	struct s_list	*next;

}					t_list;

//----------------------------------------------
void				parsing_management(t_data *data, t_list **stack_a);
void				ft_strjoin_push_swap(t_data *data, int i);
void				join_arguments(t_data *data);
void				check_char(t_data *data);
void				clean_all(t_data *data);
void				error(t_data *data);
void				display_error(void);
char				**split(t_data *data, char *str, char c);

//---------------------------------------------------

void				make_list(t_data *data, t_list **stack_a);
t_list				*ft_lstnew(int value);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
