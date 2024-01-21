/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:11:38 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 21:02:13 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			p = (char *)s;
		s++;
	}
	if (p)
		return (p);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char *str = "hello world";
    int c = 'o';
    printf("ft_strrchr:%s\n", ft_strrchr(str, c));
    printf("strrchr:%s\n", strrchr(str, c));
}*/
