/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:06:08 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 20:06:30 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (tab == NULL)
		return (NULL);
	p = tab;
	while (*s1 != '\0')
		*tab++ = *s1++;
	while (*s2 != '\0')
		*tab++ = *s2++;
	*tab = '\0';
	return (p);
}
