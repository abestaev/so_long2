/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:17:55 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 20:17:56 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tab;

	tab = s;
	while (n > 0)
	{
		if (*tab == (unsigned char)c)
			return ((void *)tab);
		tab++;
		n--;
	}
	return (NULL);
}
