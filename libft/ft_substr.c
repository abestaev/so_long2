/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:06:38 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 22:14:12 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	maxlen;

	maxlen = ft_strlen(s) - start;
	if (s == NULL)
		return (NULL);
	if (start < (unsigned int) ft_strlen(s))
	{
		if (maxlen > len)
		{
			tab = (char *)ft_calloc(sizeof(char), len + 1);
			if (tab == NULL)
				return (NULL);
		}
		else
		{
			tab = (char *)ft_calloc(sizeof(char), maxlen + 1);
			if (tab == NULL)
				return (NULL);
		}
		ft_strlcpy(tab, &s[start], len + 1);
	}
	else
		tab = (char *)ft_calloc(1, 1);
	return (tab);
}
