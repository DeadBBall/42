/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:10:21 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/05 16:01:17 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	print_s(va_list ap)
{
	char	*c;

	c = va_arg(ap, char *);
	return (write_char(c));
}

int	print_d(va_list ap)
{
	char	*c;
	int		n;

	c = ft_itoa(va_arg(ap, int));
	if (!c)
		return (-1);
	n = write_char(c);
	free(c);
	return (n);
}
