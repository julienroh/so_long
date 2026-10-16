/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:56:24 by jroh              #+#    #+#             */
/*   Updated: 2025/12/02 16:00:00 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
}

static int	key_handle(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 65361)
		move_player(game, 0, -1);
	if (keycode == 65363)
		move_player(game, 0, 1);
	if (keycode == 65362)
		move_player(game, -1, 0);
	if (keycode == 65364)
		move_player(game, 1, 0);
	return (0);
}

void	open_window(t_game *game)
{
	int	x;
	int	y;

	if (game->width > 1920)
		game->width = 1920;
	if (game->height > 1080)
		game->height = 1080;
	x = game->width * T_S;
	y = game->height * T_S;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x, y, "MyGame");
	game->img_w = mlx_xpm_file_to_image(game->mlx, "text/w.xpm", &x, &y);
	game->img_esc = mlx_xpm_file_to_image(game->mlx, "text/esc.xpm", &x, &y);
	game->img_p_u = mlx_xpm_file_to_image(game->mlx, "text/p_u.xpm", &x, &y);
	game->img_p_d = mlx_xpm_file_to_image(game->mlx, "text/p_d.xpm", &x, &y);
	game->img_p_r = mlx_xpm_file_to_image(game->mlx, "text/p_r.xpm", &x, &y);
	game->img_p_l = mlx_xpm_file_to_image(game->mlx, "text/p_l.xpm", &x, &y);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "text/c.xpm", &x, &y);
	game->img_f = mlx_xpm_file_to_image(game->mlx, "text/f.xpm", &x, &y);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, key_handle, game);
}
