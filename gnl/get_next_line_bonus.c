/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:51:07 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/06 19:21:17 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*ft_lstnew(int fd)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->save = NULL;
	lst->next = NULL;
	return (lst);
}

static t_list	*ft_lstfind(t_list **lst, int fd)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = ft_lstnew(fd);
		return (*lst);
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew(fd);
	return (tmp->next);
}

static void	ft_lstfree(t_list **bonus, int fd)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *bonus;
	if (tmp->fd == fd)
	{
		*bonus = tmp->next;
		free(tmp->save);
		if (*bonus)
			tmp->save = NULL;
		return ;
	}
	while (tmp->next)
	{
		if (tmp->next->fd == fd)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			free(tmp2->save);
			tmp2->save = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}

static char	*ft_prt(t_list **bonus, t_list *lst, int idx, int fd)
{
	char	*tmp;
	char	*ret;

	if (!(*bonus))
		return (NULL);
	tmp = lst->save;
	if (idx == -1 || (lst->save)[idx + 1] == 0)
		ret = ft_substr(lst->save, 0, ft_strchr(lst->save, 0));
	else
	{
		ret = ft_substr(lst->save, 0, idx + 1);
		lst->save = ft_substr(lst->save, idx + 1,
				ft_strchr(lst->save, 0) - (idx + 1));
		free(tmp);
		return (ret);
	}
	ft_lstfree(bonus, fd);
	free(lst);
	lst = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*bonus;
	t_list			*lst;
	char			buf[BUFFER_SIZE + 1];
	int				idx;
	int				line;

	lst = NULL;
	idx = read(fd, buf, BUFFER_SIZE);
	if (idx == -1 && bonus)
		return (ft_prt(&bonus, ft_lstfind(&bonus, fd),
				ft_strchr(ft_lstfind(&bonus, fd)->save, '\n'), fd));
	if (idx != -1)
		lst = ft_lstfind(&bonus, fd);
	while (idx > 0)
	{
		buf[idx] = 0;
		lst->save = ft_strjoin(lst->save, buf);
		line = ft_strchr(lst->save, '\n');
		if (line != -1)
			return (ft_prt(&bonus, lst, line, fd));
		idx = read(fd, buf, BUFFER_SIZE);
	}
	if (!idx)
		return (ft_prt(&bonus, lst, ft_strchr(lst->save, '\n'), fd));
	return (NULL);
}
