/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:15:58 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:40 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	idx = 0;
	if (!n)
		return (0);
	while (idx + 1 < n && c1[idx] && c2[idx])
	{
		if (c1[idx] == c2[idx])
			idx++;
		else
			return (c1[idx] - c2[idx]);
	}
	return (c1[idx] - c2[idx]);
}
