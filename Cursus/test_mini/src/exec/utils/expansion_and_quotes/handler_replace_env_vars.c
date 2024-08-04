/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_replace_env_vars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:03:41 by junsan            #+#    #+#             */
/*   Updated: 2024/08/01 12:29:28 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_var_value(const char *var_value, char *res, size_t *j)
{
	size_t	var_value_len;

	var_value_len = ft_strlen(var_value);
	ft_strlcpy(res + *j, var_value, var_value_len + 1);
	*j += var_value_len;
	free((char *)var_value);
	var_value = NULL;
}

static void	handle_expansion_var(t_env_var *env_var, char c)
{
	char	*var_value;

	env_var->i += 2;
	if (c == '?')
	{
		var_value = process_replace_expansion_var(env_var->info);
		if (var_value)
			copy_var_value(var_value, env_var->res, &(env_var->j));
	}
	else if (c == '_')
	{
		var_value = ft_strdup(env_var->info->env->last_arg->content);
		copy_var_value(var_value, env_var->res, &(env_var->j));
	}
}

static void	handle_simple_var(t_env_var *env_var, char *var_name)
{
	char	*var_value;

	env_var->i++;
	extract_var_name(\
			env_var->str, &(env_var->i), var_name);
	var_value = process_replace_env_vars(var_name, env_var->info);
	if (var_value)
		copy_var_value(var_value, env_var->res, &(env_var->j));
}

void	handle_dollar_sign(t_env_var *env_var)
{
	char	var_name[MAX_ARGS];

	if (env_var->str[env_var->i] == '$' && \
			(env_var->str[env_var->i + 1] == '\0' || \
			env_var->str[env_var->i + 1] == ' ' || \
			env_var->str[env_var->i + 1] == '\t' || \
			env_var->str[env_var->i + 1] == '\n'))
		env_var->res[env_var->j++] = env_var->str[env_var->i++];
	else if (env_var->str[env_var->i] == '$' && \
		env_var->str[env_var->i + 1] == '?')
		handle_expansion_var(env_var, '?');
	else if (env_var->str[env_var->i] == '$' && \
			(ft_isalnum(env_var->str[env_var->i + 1]) || \
			(env_var->str[env_var->i + 1] == '_' && \
			env_var->str[env_var->i + 2])))
		handle_simple_var(env_var, var_name);
	else if (env_var->str[env_var->i] == '$' && \
			env_var->str[env_var->i + 1] == '_' && \
			env_var->str[env_var->i + 2] == '\0' )
		handle_expansion_var(env_var, '_');
	else
		env_var->res[env_var->j++] = env_var->str[env_var->i++];
}
