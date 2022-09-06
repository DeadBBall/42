/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:01:29 by yonggkim          #+#    #+#             */
/*   Updated: 2022/09/05 16:27:06 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		write_char(char *s);
int		check_alp(char *s, int idx, va_list ap);
int		print_c(va_list ap);
int		print_s(va_list ap);
int		print_d(va_list ap);
char	*ft_itoa(int n);
int		print_u(va_list ap);
char	*ft_uitoa(int n);
int		print_p(va_list ap);
int		print_lx(va_list ap);
int		print_sx(va_list ap);

#endif
