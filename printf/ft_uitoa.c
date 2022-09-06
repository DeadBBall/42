/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:54:41 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/01 19:04:48 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	how_long(unsigned int n)
{
	int			i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_rev_arr(char *arr, int idx)
{
	int		i;
	char	tmp;

	i = 0;
	idx -= 1;
	while (i <= idx - 1)
	{
		tmp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = tmp;
		idx--;
		i++;
	}
	return ;
}

char	*ft_uitoa(int n)
{
	unsigned int	tmp;
	char			*arr;
	int				idx;

	idx = 0;
	arr = (char *)malloc(how_long(n) + 1);
	if (!arr)
		return (NULL);
	tmp = n;
	if (!n)
		arr[0] = '0';
	while (tmp)
	{
		arr[idx++] = tmp % 10 + '0';
		tmp /= 10;
	}
	ft_rev_arr(arr, how_long(n));
	arr[how_long(n)] = 0;
	return (arr);
}
