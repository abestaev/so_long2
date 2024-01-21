/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:09:54 by albestae          #+#    #+#             */
/*   Updated: 2024/01/21 15:30:16 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	char	*newstr;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	newstr = malloc(sizeof(char) * len1 + len2 + 1);
	if (!newstr)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		newstr[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		newstr[len1 + i] = s2[i];
	if (i < 0)
		i = 0;
	newstr[len1 + i] = '\0';
	if (s1)
		free (s1);
	return (newstr);
}

char	*ft_substr_free(char *s, unsigned int start, int len, int free_s)
{
	char	*newstr;
	int		i;

	if (!s)
		return (NULL);
	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	if (start < ft_strlen_gnl(s))
	{
		while (s[start + i] && i < len)
		{
			newstr[i] = s[start + i];
			i++;
		}
	}
	newstr[i] = '\0';
	if (free_s && s)
		free(s);
	return (newstr);
}
