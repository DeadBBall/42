/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:51:05 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/24 20:25:50 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# if BUFFER_SIZE < 1
#  error BUFFER_SIZE error
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*save;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strchr(const char *s, int c);

#endif
