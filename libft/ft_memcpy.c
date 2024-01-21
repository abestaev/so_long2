/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:17:02 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 20:17:03 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	if (!dest && !src)
		return (dest);
	t1 = (unsigned char *)dest;
	t2 = (unsigned char *)src;
	while (n > 0)
	{
		*t1++ = *t2++;
		n--;
	}
	return (dest);
}
