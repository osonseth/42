/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:15:32 by mmauchre          #+#    #+#             */
/*   Updated: 2024/05/04 00:52:07 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
	t_list	*current;

	
	current = stack;
	if (current == NULL)
		ft_printf("NULL\n");
	while (current)
	{
		ft_printf("val = %d\n", current->value);
		current = current->next;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstnew(int value)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}

void	make_list(t_data *data, t_list **stack_a)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (i < data->array_number_height)
	{
		temp = ft_lstnew(ft_atoi(data->array_number[i]));
		if (temp == NULL)
		{
			ft_lstclear(stack_a);
			perror("Error : memory allocation\n");
			clean_parsing(data);
			exit(EXIT_FAILURE);
		}
		check_double(stack_a, temp, data);
		ft_lstadd_back(stack_a, temp);
		i++;
	}
	return ;
}
