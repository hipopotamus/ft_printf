/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:40:32 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 22:24:04 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_len(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	get_word_num(char const *s, char c)
{
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			i += get_word_len(&s[i], c);
		}
		else
			i++;
	}
	return (cnt);
}

static int		memerr_free(char **res, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char		**res;
	size_t		s_i;
	size_t		r_i;
	size_t		len_word;

	if (!(res = (char**)malloc(sizeof(char*) * (get_word_num(s, c) + 1))))
		return (NULL);
	s_i = 0;
	r_i = 0;
	while (s[s_i])
	{
		if (s[s_i] != c)
		{
			len_word = get_word_len(&s[s_i], c);
			res[r_i] = (char*)malloc(sizeof(char) * (len_word) + 1);
			if (res[r_i] == NULL && memerr_free(res, r_i))
				return (0);
			ft_strlcpy(res[r_i], &s[s_i], len_word + 1);
			s_i += len_word - 1;
			r_i++;
		}
		s_i++;
	}
	res[r_i] = NULL;
	return (res);
}
