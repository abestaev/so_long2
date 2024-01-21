/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:13:56 by albestae          #+#    #+#             */
/*   Updated: 2023/11/20 14:42:37 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_belong(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static unsigned int	ft_get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && ft_belong(s1[i], set) == 1)
		i++;
	return (i);
}

static unsigned int	ft_get_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_belong(s1[i], set) != 1)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*tab;
	size_t			len;

	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	len = end - start + 1;
	tab = ft_substr(s1, start, len);
	if (!tab)
		return (NULL);
	return (tab);
}
