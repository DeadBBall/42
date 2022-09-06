/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:37:45 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/06 19:16:38 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_prt(char **save, int idx)
{
	char	*c;
	char	*ret;

	ret = NULL;
	c = *save;
	if (idx == -1 || (*save)[idx + 1] == 0)
	{
		ret = ft_substr(*save, 0, ft_strchr(*save, 0));
		free(*save);
		*save = NULL;
	}
	else
	{
		ret = ft_substr(*save, 0, idx + 1);
		*save = ft_substr(*save, idx + 1, ft_strchr(*save, 0) - (idx + 1));
		free(c);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save = NULL;
	int			idx;
	int			line;

	idx = read(fd, buf, BUFFER_SIZE);
	while (idx && idx != -1)
	{
		buf[idx] = 0;
		save = ft_strjoin(save, buf);
		line = ft_strchr(save, '\n');
		if (line != -1)
			return (ft_prt(&save, line));
		idx = read(fd, buf, BUFFER_SIZE);
	}
	if (save != NULL)
		return (ft_prt(&save, ft_strchr(save, '\n')));
	return (NULL);
}
