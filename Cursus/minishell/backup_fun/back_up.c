

void	pipe_token(t_node **lst)
{
	char	*tmp;

	tmp = ft_strdup("|");
	ft_lstadd_back(lst, ft_lstnew(tmp));
}

void	heredoc_token(t_node **lst, int *i)
{
	char	*tmp;

	tmp = ft_strdup("<<");
	ft_lstadd_back(lst, ft_lstnew(tmp));
	(*i)++;
}

void	append_redirect_token(t_node **lst, int *i)
{
	char	*tmp;

	tmp = ft_strdup(">>");
	ft_lstadd_back(lst, ft_lstnew(tmp));
	(*i)++;
}

void	output_redirect_token(t_node **lst)
{
	char	*tmp;

	tmp = ft_strdup(">");
	ft_lstadd_back(lst, ft_lstnew(tmp));
}

void	input_redirect_token(t_node **lst)
{
	char	*tmp;

	tmp = ft_strdup("<");
	ft_lstadd_back(lst, ft_lstnew(tmp));
}

void	create_token(char *str, t_node **lst, int *i)
{
	char	*tmp;

	tmp = ft_strdup_two(str);
	ft_lstadd_back(lst, ft_lstnew(tmp));
	(*i) += (ft_strlen_two(str) - 1);
}

void	make_lst(char *str, t_node **lst)
{
	int (i) = 0;
	while (str[i])
	{
		skype_space(&str[i],&i);
		if (!ft_strncmp(&str[i], "<<", 2))
			heredoc_token(lst, &i);
		else if (!ft_strncmp(&str[i], ">>", 2))
			append_redirect_token(lst, &i);
		else if (!ft_strncmp(&str[i], ">", 1))
			output_redirect_token(lst);
		else if (!ft_strncmp(&str[i], "<", 1))
			input_redirect_token(lst);
		else if (!ft_strncmp(&str[i], "|", 1))
			pipe_token(lst);
		else if (str[i] != '\0')
			create_token(&str[i], lst, &i);
		if (str[i])
			i++;
	}
}

t_node	*ft_lstnew(void *content)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	list->token = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

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

