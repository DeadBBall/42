/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:44 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/05 16:11:29 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	how_long(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	print_u(va_list ap)
{
	char	*c;
	int		n;

	c = ft_uitoa(va_arg(ap, int));
	if (!c)
		return (-1);
	n = write_char(c);
	free(c);
	return (n);
}

int	print_p(va_list ap)
{
	unsigned long		a;
	int					idx;
	char				*c;
	int					len;

	a = va_arg(ap, long);
	write(1, "0x", 2);
	idx = how_long(a);
	len = idx;
	c = malloc(len + 1);
	if (!c)
		return (-1);
	c[len] = 0;
	if (!a)
		c[0] = '0';
	while (a)
	{
		c[--idx] = "0123456789abcdef"[a % 16];
		a /= 16;
	}
	write(1, c, len);
	free(c);
	return (len + 2);
}

int	print_lx(va_list ap)
{
	unsigned int		a;
	int					idx;
	char				*c;
	int					len;

	a = va_arg(ap, int);
	idx = how_long(a);
	len = idx;
	c = malloc(len + 1);
	if (!c)
		return (-1);
	c[len] = 0;
	if (!a)
		c[0] = '0';
	while (a)
	{
		c[--idx] = "0123456789abcdef"[a % 16];
		a /= 16;
	}
	write(1, c, len);
	free(c);
	return (len);
}

int	print_sx(va_list ap)
{
	unsigned int		a;
	int					idx;
	char				*c;
	int					len;

	a = va_arg(ap, int);
	idx = how_long(a);
	len = idx;
	c = malloc(len + 1);
	if (!c)
		return (-1);
	c[len] = 0;
	if (!a)
		c[0] = '0';
	while (a)
	{
		c[--idx] = "0123456789ABCDEF"[a % 16];
		a /= 16;
	}
	write(1, c, len);
	free(c);
	return (len);
}
