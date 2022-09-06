/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:04:40 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:36 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tmp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	ft_strlcpy(tmp + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (tmp);
}
