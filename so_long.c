/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:00:32 by albestae          #+#    #+#             */
/*   Updated: 2024/01/21 17:01:09 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	ft_str_to_tab(&game, argv[1]);
	ft_init(&game);
	ft_check_map(&game);
	if (ft_load_images(&game))
	{
		ft_putendl_fd("Error\nerror when loading image", 2);
		ft_exit_properly(&game);
	}
	ft_draw_map(&game);
	mlx_hook(game.mlx_win, 33, 1L << 17, &ft_escape, &game);
	mlx_loop_hook(game.mlx_win, &ft_no_event, &game);
	mlx_key_hook(game.mlx_win, &ft_key_press, &game);
	mlx_loop(game.mlx);
}
