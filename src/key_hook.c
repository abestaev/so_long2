/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:28:06 by albestae          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:35 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_no_event(t_game *game)
{
	ft_putstr_fd("move count: ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putstr_fd(" \r", 1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
	return (1);
}

int	ft_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (ft_escape(game));
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (ft_move(key, game));
	return (1);
}
