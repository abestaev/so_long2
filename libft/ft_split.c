/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:20:24 by albestae          #+#    #+#             */
/*   Updated: 2023/11/21 13:40:15 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c)
{
	int			word;
	char const	*s;

	word = 0;
	s = str;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (word);
}

static int	ft_letter_count(char const *str, char c)
{
	int			letter;
	char const	*s;

	letter = 0;
	s = str;
	while (*s == c && *s)
		s++;
	while (*s != c && *s++)
		letter++;
	return (letter);
}

static char	*ft_clean(char **tab, int i)
{
	while (i > 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	char	*tab;
	int		i;

	i = 0;
	t = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!s || t == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tab = (char *)malloc(sizeof(char) * ft_letter_count(s, c) + 1);
			if (tab == NULL)
				return ((char **)ft_clean(t, i));
			ft_strlcpy(tab, s, ft_letter_count(s, c) + 1);
			*t++ = tab;
			i++;
			while (*s != c && *(s + 1) != '\0')
				s++;
		}
		s++;
	}
	*t = 0;
	return (t - i);
}
