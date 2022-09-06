/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:49:58 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:40 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	size_t			len;
	char			*arr;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		arr[idx] = f(idx, s[idx]);
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}
