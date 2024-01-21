/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:13:14 by albestae          #+#    #+#             */
/*   Updated: 2023/11/02 20:13:14 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = (char *)malloc(sizeof(char) * (ft_count_digit(n) + 1));
	if (!tab)
		return (NULL);
	i = ft_count_digit(n);
	tab[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		tab[0] = '-';
	}
	while (n)
	{
		tab[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (tab);
}
