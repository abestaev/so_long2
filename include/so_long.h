/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:02:49 by albestae          #+#    #+#             */
/*   Updated: 2024/01/21 16:43:05 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibX/mlx.h"
# include "../minilibX/mlx_int.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define SIZE 64

# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	char		**tab;
	char		**check;
	int			collect;
	int			joueur;
	int			exit_count;
	int			count;
	int			i_pl;
	int			j_pl;
	size_t		len;
	int			height;
	t_img		*background;
	t_img		*player;
	t_img		*gold;
	t_img		*wall;
	t_img		*exit;
}				t_game;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
}				t_data;

int				ft_check_args(int argc, char **argv);
int				ft_check_map(t_game *game);
int				ft_check_wall(t_game *game);
int				ft_check_wall_top(t_game *game);
int				ft_check_len(t_game *game);
int				ft_check_element(t_game *game);
void			ft_send_error(t_game *game, char *str);
int				flood_fill(t_game *game, int x, int y);
int				ft_check_valid_path(t_game *game);

char			*ft_ber_to_str(char *map);
void			ft_str_to_tab(t_game *game, char *map);
void			ft_init(t_game *game);
int				ft_init_data(t_game *game);

int				ft_draw_tile(t_game *game, t_img *img, int x, int y);
void			ft_draw_map(t_game *game);
void			my_mlx_pixel_put(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *mlx_img, int i, int j);

int				ft_load(t_game *game, t_img **img, char *path);
int				ft_load_images(t_game *game);
int				ft_load_wall(t_game *game);
int				ft_no_event(t_game *game);
int				ft_escape(t_game *game);
int				ft_exit_properly(t_game *game);
int				ft_key_press(int k, t_game *game);

int				ft_move(int key, t_game *game);
int				ft_move_right(t_game *game);
int				ft_move_left(t_game *game);
int				ft_move_up(t_game *game);
int				ft_move_down(t_game *game);

int				ft_is_move_valid(t_game *game, char tile);
void			ft_print_move(t_game *game);

#endif
