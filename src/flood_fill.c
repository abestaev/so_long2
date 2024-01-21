/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:11:14 by albestae          #+#    #+#             */
/*   Updated: 2024/01/17 19:11:15 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_game *game, int x, int y)
{
	if (game->check[x][y] == '0' || game->check[x][y] == 'C')
	{
		game->check[x][y] = '2';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
	return (0);
}

int	ft_check_valid_path(t_game *game)
{
	int	i;
	int	j;

	game->check[game->i_pl][game->j_pl] = '0';
	flood_fill(game, game->i_pl, game->j_pl);
	i = 0;
	while (game->check[i])
	{
		j = 0;
		while (game->check[i][j])
		{
			if (game->check[i][j] == 'C')
				return (1);
			else if (game->check[i][j] == 'E')
			{
				if (game->check[i + 1][j] != '2' && game->check[i - 1][j] != '2'
					&& game->check[i][j + 1] != '2' && game->check[i][j
					- 1] != '2')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
