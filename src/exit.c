/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:22:07 by albestae          #+#    #+#             */
/*   Updated: 2024/01/17 19:03:54 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->mlx_img);
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->gold);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->mlx_win);
	i = 0;
	while (i < game->height)
	{
		free(game->tab[i]);
		free(game->check[i++]);
	}
	free(game->tab);
	free(game->check);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	ft_exit_properly(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->mlx_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	i = 0;
	while (i < game->height)
	{
		free(game->tab[i]);
		free(game->check[i++]);
	}
	free(game->tab);
	free(game->check);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
