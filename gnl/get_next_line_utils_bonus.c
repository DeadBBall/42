/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:50:59 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/23 20:19:34 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	if (!s)
		return (-1);
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return (idx);
		idx++;
	}
	if (s[idx] == (unsigned char)c)
		return (idx);
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strchr(src, 0));
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strchr(src, 0));
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strchr(s, 0) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tmp = (char *)malloc((ft_strchr(s1, 0) + ft_strchr(s2, 0) + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strchr(s1, 0) + 1);
	ft_strlcpy(tmp + ft_strchr(s1, 0), s2, ft_strchr(s2, 0) + 1);
	free(s1);
	return (tmp);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*tmp;
	int		i;

	if (!s || start >= ft_strchr(s, 0) || !len)
		return (NULL);
	i = 0;
	if (len > ft_strchr(s, 0) - start)
		len = ft_strchr(s, 0) - start;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
