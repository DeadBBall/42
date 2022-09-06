/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:12:33 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:34 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;
	int	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx < len)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (!(unsigned char)c)
		return ((char *)&s[idx]);
	return (NULL);
}
