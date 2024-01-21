/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:09:00 by albestae          #+#    #+#             */
/*   Updated: 2024/01/17 19:11:04 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst = mlx_img->data + (y * mlx_img->size_line + x * (mlx_img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->data + (x * img->bpp / 8 + y
			* img->size_line)));
}

int	ft_load(t_game *game, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*img == NULL)
		return (1);
	(**img).width = width;
	(**img).height = height;
	return (0);
}

int	ft_load_images(t_game *game)
{
	if (ft_load(game, &game->background, "images/background.xpm"))
		return (1);
	if (ft_load(game, &game->exit, "images/exit.xpm"))
	{
		mlx_destroy_image(game->mlx, game->background);
		return (1);
	}
	if (ft_load(game, &game->gold, "images/gold.xpm"))
	{
		mlx_destroy_image(game->mlx, game->exit);
		mlx_destroy_image(game->mlx, game->background);
		return (1);
	}
	if (ft_load(game, &game->player, "images/player.xpm"))
	{
		mlx_destroy_image(game->mlx, game->exit);
		mlx_destroy_image(game->mlx, game->background);
		mlx_destroy_image(game->mlx, game->gold);
		return (1);
	}
	if (ft_load_wall(game))
		return (1);
	return (0);
}

int	ft_load_wall(t_game *game)
{
	if (ft_load(game, &game->wall, "images/wall.xpm"))
	{
		mlx_destroy_image(game->mlx, game->player);
		mlx_destroy_image(game->mlx, game->exit);
		mlx_destroy_image(game->mlx, game->background);
		mlx_destroy_image(game->mlx, game->gold);
		return (1);
	}
	return (0);
}
