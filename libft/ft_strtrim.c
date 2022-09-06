/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:04:51 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:42 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const s1, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (i <= size)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		len;
	int		idx;

	if (!s1 || !set)
		return (NULL);
	idx = 0;
	len = ft_strlen(s1) - 1;
	while (ft_check(s1[idx], set))
		idx++;
	while (len >= 0 && ft_check(s1[len], set))
		len--;
	if (len < idx)
		return (ft_strdup(""));
	tmp = (char *)malloc(len - idx + 2);
	if (!tmp)
		return (NULL);
	ft_cpy(tmp, (char *)s1 + idx, len - idx + 2);
	return (tmp);
}
