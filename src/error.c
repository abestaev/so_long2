/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:03:53 by albestae          #+#    #+#             */
/*   Updated: 2024/01/08 05:08:14 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\ninvalid number of argument", 2);
		exit(1);
	}
	if (ft_strrchr(argv[1], '.') == NULL)
	{
		ft_putendl_fd("Error\ninvalid argument", 2);
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", ft_strlen(argv[1])) != 0)
	{
		ft_putendl_fd("Error\nfile must be of type <name>.ber", 2);
		exit(1);
	}
	return (0);
}

void	ft_send_error(t_game *game, char *str)
{
	ft_putendl_fd(str, 2);
	ft_exit_properly(game);
}
