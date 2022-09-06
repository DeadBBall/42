/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:04:54 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:42 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s || start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
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
