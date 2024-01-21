/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:31:43 by albestae          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:41 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_right(t_game *game)
{
	if (ft_is_move_valid(game, game->tab[game->i_pl][game->j_pl + 1]))
		return (1);
	game->tab[game->i_pl][game->j_pl] = '0';
	game->tab[game->i_pl][game->j_pl + 1] = 'P';
	game->j_pl += 1;
	ft_print_move(game);
	ft_draw_tile(game, game->background, (game->j_pl - 1) * SIZE, (game->i_pl)
		* SIZE);
	ft_draw_tile(game, game->player, (game->j_pl) * SIZE, (game->i_pl) * SIZE);
	return (0);
}

int	ft_move_left(t_game *game)
{
	if (ft_is_move_valid(game, game->tab[game->i_pl][game->j_pl - 1]))
		return (1);
	game->tab[game->i_pl][game->j_pl] = '0';
	game->tab[game->i_pl][game->j_pl - 1] = 'P';
	game->j_pl -= 1;
	ft_print_move(game);
	ft_draw_tile(game, game->background, (game->j_pl + 1) * SIZE, (game->i_pl)
		* SIZE);
	ft_draw_tile(game, game->player, (game->j_pl) * SIZE, (game->i_pl) * SIZE);
	return (0);
}

int	ft_move_up(t_game *game)
{
	if (ft_is_move_valid(game, game->tab[game->i_pl - 1][game->j_pl]))
		return (1);
	game->tab[game->i_pl][game->j_pl] = '0';
	game->tab[game->i_pl - 1][game->j_pl] = 'P';
	game->i_pl -= 1;
	ft_print_move(game);
	ft_draw_tile(game, game->background, (game->j_pl) * SIZE, (game->i_pl + 1)
		* SIZE);
	ft_draw_tile(game, game->player, (game->j_pl) * SIZE, (game->i_pl) * SIZE);
	return (0);
}

int	ft_move_down(t_game *game)
{
	if (ft_is_move_valid(game, game->tab[game->i_pl + 1][game->j_pl]))
		return (1);
	game->tab[game->i_pl][game->j_pl] = '0';
	game->tab[game->i_pl + 1][game->j_pl] = 'P';
	game->i_pl += 1;
	ft_print_move(game);
	ft_draw_tile(game, game->background, (game->j_pl) * SIZE, (game->i_pl - 1)
		* SIZE);
	ft_draw_tile(game, game->player, (game->j_pl) * SIZE, (game->i_pl) * SIZE);
	return (0);
}

int	ft_move(int key, t_game *game)
{
	if (key == RIGHT)
		ft_move_right(game);
	if (key == LEFT)
		ft_move_left(game);
	if (key == UP)
		ft_move_up(game);
	if (key == DOWN)
		ft_move_down(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
	return (1);
}
