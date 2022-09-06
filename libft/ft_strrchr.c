/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:16:55 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:41 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)&s[idx]);
		idx--;
	}
	if (s[idx] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
