/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:43:23 by albestae          #+#    #+#             */
/*   Updated: 2024/01/17 19:10:39 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_str_to_tab(t_game *game, char *map)
{
	char	*str;

	str = ft_ber_to_str(map);
	game->tab = ft_split(str, '\n');
	game->check = ft_split(str, '\n');
	free(str);
}

char	*ft_ber_to_str(char *map)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nfile cannot be read", 2);
		exit(1);
	}
	str = get_next_line(fd);
	tmp = "initilisation";
	while (tmp)
	{
		tmp = get_next_line(fd);
		str = ft_strjoin_free(str, tmp);
		free(tmp);
	}
	close(fd);
	return (str);
}

int	ft_check_wall(t_game *game)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_check_wall_top(game);
	while (game->tab[i])
	{
		c = game->tab[i][ft_strlen(game->tab[i]) - 1];
		if (game->tab[i][0] != '1' || c != '1')
			return (1);
		i++;
	}
	j = 0;
	while (game->tab[i - 1][j])
	{
		if (game->tab[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	ft_init(t_game *game)
{
	game->collect = 0;
	game->joueur = 0;
	game->exit_count = 0;
	game->count = 0;
	ft_init_data(game);
	game->len = ft_strlen(game->tab[0]);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit(1);
	game->mlx_win = mlx_new_window(game->mlx, game->len * SIZE, game->height
			* SIZE, "so_long");
	game->mlx_img = mlx_new_image(game->mlx, game->len * SIZE, game->height
			* SIZE);
}
