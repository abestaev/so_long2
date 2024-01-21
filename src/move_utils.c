/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:33:06 by albestae          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:38 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_move_valid(t_game *game, char tile)
{
	if (tile == '1')
		return (1);
	if (tile == 'C')
		game->collect -= 1;
	if (tile == 'E' && game->collect == 0)
		ft_escape(game);
	if (tile == 'E' && game->collect > 0)
		return (1);
	game->count++;
	return (0);
}

void	ft_print_move(t_game *game)
{
	ft_putstr_fd(" move count : ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putstr_fd(" \r", 1);
}
