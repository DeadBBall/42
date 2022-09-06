/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:22:31 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:12 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*del_ws(char *arr)
{
	while ((9 <= *arr && *arr <= 13) || *arr == 32)
		arr++;
	return (arr);
}

static char	*check_sign(char *arr, int *sign)
{
	if (*arr == '-')
	{
		*sign *= -1;
		arr++;
	}
	else if (*arr == '+')
		arr++;
	return (arr);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == 0)
		return (0);
	str = check_sign(del_ws((char *)str), &sign);
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (sign * num);
}
