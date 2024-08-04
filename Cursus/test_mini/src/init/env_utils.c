/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:04:20 by junsan            #+#    #+#             */
/*   Updated: 2024/07/31 14:47:24 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_split(const char *str, char **name, char **content)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
	{
		*name = (char *)str;
		*content = NULL;
		return ;
	}
	*name = ft_strndup(str, i);
	*content = ft_strndup(str + i + 1, ft_strlen(str) - i - 1);
	if (*content == NULL)
	{
		free(*name);
		*name = NULL;
	}
}

static void	clear_pwd_oldpwd_under_score(t_env *head)
{
	if (head->pwd)
	{
		if (head->pwd->name)
			free(head->pwd->name);
		if (head->pwd->content)
			free(head->pwd->content);
		free(head->pwd);
	}
	if (head->old_pwd)
	{
		if (head->old_pwd->name)
			free(head->old_pwd->name);
		if (head->old_pwd->content)
			free(head->old_pwd->content);
		free(head->old_pwd);
	}
	if (head->last_arg)
	{
		if (head->last_arg->name)
			free(head->last_arg->name);
		if (head->last_arg->content)
			free(head->last_arg->content);
		free(head->last_arg);
	}
}

void	clear_env(t_env *head)
{
	t_env	*cur;

	if (head == NULL)
		return ;
	clear_pwd_oldpwd_under_score(head);
	while (head)
	{
		cur = head->next;
		free(head->name);
		head->name = NULL;
		if (head->content)
		{
			free(head->content);
			head->content = NULL;
		}
		free(head);
		head = NULL;
		head = cur;
	}
	head = NULL;
}

size_t	env_size(t_env *head)
{
	t_env	*cur;
	size_t	size;

	size = 0;
	cur = head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

bool	is_check_key(const char *name, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
			return (true);
		env = env->next;
	}
	return (false);
}
