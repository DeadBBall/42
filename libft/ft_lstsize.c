/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:08:37 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:26 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		tmp;

	cur = lst;
	tmp = 0;
	while (cur)
	{
		cur = cur->next;
		tmp++;
	}
	return (tmp);
}
