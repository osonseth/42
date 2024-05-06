/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:53:43 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/06 08:59:25 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
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
	long int		value;
	struct s_list	*next;

}					t_list;
//----------------------------------------------
void				parsing_management(t_data *data, t_list **stack_a);
void				ft_strjoin_push_swap(t_data *data, int i);
void				join_arguments(t_data *data);
void				check_char(t_data *data);
void				clean_parsing(t_data *data);
void				error(t_data *data);
void				display_error(void);
char				**split(t_data *data, char *str, char c);
//---------------------------------------------------
void				make_list(t_data *data, t_list **stack_a);
t_list				*ft_lstnew(long int value);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
bool				lst_is_shorted(t_list *lst);
void				print_list(t_list *stack);
void				check_double(t_list **stack_a, t_list *new, t_data *data);
void				management(t_data *data, t_list **stack_a,
						t_list **stack_b);
//----------------------------------------------------
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				print_sa(t_list **stack_a);
void				print_sb(t_list **stack_b);
void				print_ss(t_list **stack_a, t_list **stack_b);
void				print_pb(t_list **stack_a, t_list **stack_b);
void				print_pa(t_list **stack_a, t_list **stack_b);
void				print_ra(t_list **stack_a);
void				print_rb(t_list **stack_b);
void				print_rr(t_list **stack_a, t_list **stack_b);
void				print_rra(t_list **stack_a);
void				print_rrb(t_list **stack_b);
void				print_rrr(t_list **stack_a, t_list **stack_b);

#endif
