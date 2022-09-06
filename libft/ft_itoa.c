/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:21:50 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:20 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_long(int n)
{
	int			i;
	long long	k;

	i = 0;
	k = n;
	if (!n)
		return (1);
	else if (n < 0)
	{
		i++;
		k = (long long)n * -1;
	}
	while (k)
	{
		k /= 10;
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

char	*ft_itoa(int n)
{
	long long	tmp;
	char		*arr;
	int			idx;

	idx = 0;
	arr = (char *)malloc(how_long(n) + 1);
	if (!arr)
		return (NULL);
	tmp = n;
	if (!n)
		arr[0] = '0';
	else if (n < 0)
	{
		tmp = (long long)n * -1;
		arr[how_long(n) - 1] = '-';
	}
	while (tmp)
	{
		arr[idx++] = tmp % 10 + '0';
		tmp /= 10;
	}
	ft_rev_arr(arr, how_long(n));
	arr[how_long(n)] = 0;
	return (arr);
}
