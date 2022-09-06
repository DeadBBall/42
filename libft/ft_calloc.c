/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:47:49 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:14 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*arr;

	if (cnt * n && (cnt * n < cnt || cnt * n < n))
		return (NULL);
	arr = malloc(cnt * n);
	if (!arr)
		return (NULL);
	ft_bzero(arr, cnt * n);
	return (arr);
}
