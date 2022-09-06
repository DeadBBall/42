/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:16:32 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:41 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	while (s1[idx1] && s2[idx2] && idx1 + idx2 < n)
	{
		if (s1[idx1 + idx2] == s2[idx2])
			idx2++;
		else
		{
			idx1++;
			idx2 = 0;
		}
	}
	if (!s2[idx2])
		return ((char *)&s1[idx1]);
	return (NULL);
}
