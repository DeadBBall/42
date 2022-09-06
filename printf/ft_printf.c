/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:00:56 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/05 16:13:45 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		while (s[idx])
			write(1, &s[idx++], 1);
	return (idx);
}

int	check_alp(char *s, int idx, va_list ap)
{
	if (s[idx] == 'c')
		return (print_c(ap));
	else if (s[idx] == 's')
		return (print_s(ap));
	else if (s[idx] == 'd' || s[idx] == 'i')
		return (print_d(ap));
	else if (s[idx] == 'p')
		return (print_p(ap));
	else if (s[idx] == 'u')
		return (print_u(ap));
	else if (s[idx] == 'X')
		return (print_sx(ap));
	else if (s[idx] == 'x')
		return (print_lx(ap));
	else if (s[idx] == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		idx;
	int		num;
	int		check;

	num = 0;
	idx = -1;
	va_start(ap, s);
	while (s[++idx])
	{
		if (s[idx] == '%')
		{
			check = check_alp((char *)s, idx + 1, ap);
			idx++;
			if (check == -1 || num < 0)
				return (-1);
			else
				num += check;
		}
		else
			num += write(1, &s[idx], 1);
	}
	va_end(ap);
	return (num);
}
