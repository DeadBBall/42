/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:22:59 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:13 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*((unsigned char *)dest + i) = 0;
		i++;
	}
	return ;
}
