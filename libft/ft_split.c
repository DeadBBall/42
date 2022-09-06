/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:55:36 by yonggkim          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:33 by yonggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(char *str, char charset)
{
	int	idx;
	int	word;

	idx = 0;
	word = 0;
	while (str[idx])
	{
		if (str[idx] != charset)
		{
			if ((str[idx + 1] == charset) || str[idx + 1] == '\0')
				word++;
		}
		idx++;
	}
	return (word);
}

static char	*ft_maker(char *s, char c, int *idx)
{
	char	*arr;
	int		len;
	int		a_idx;

	len = 0;
	while (s[len + *idx] != c && s[len + *idx] != '\0')
		len++;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	a_idx = 0;
	while (s[*idx] != c && s[*idx] != '\0')
	{
		arr[a_idx] = s[*idx];
		(*idx)++;
		a_idx++;
	}
	arr[a_idx] = 0;
	return (arr);
}

static int	check_mem(char **arr, char *arrnow, int word)
{
	int	idx;

	idx = 0;
	if (!arrnow)
	{
		while (idx < word)
			free(*arr + idx++);
		free(arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		idx;
	int		a_idx;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (check_word((char *)s, c) + 1));
	if (!arr)
		return (NULL);
	idx = 0;
	a_idx = 0;
	while (a_idx < check_word((char *)s, c))
	{
		if (s[idx] != c)
		{
			arr[a_idx] = ft_maker((char *)s, c, &idx);
			if (check_mem(arr, *arr + a_idx++, check_word((char *)s, c)))
				return (NULL);
		}
		else
			idx++;
	}
	arr[a_idx] = NULL;
	return (arr);
}
