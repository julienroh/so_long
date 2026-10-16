/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:06 by jroh              #+#    #+#             */
/*   Updated: 2025/12/06 12:19:50 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int i, int j)
{
	int	new_row;
	int	new_col;

	new_row = game->row_player + i;
	new_col = game->col_player + j;
	if (game->map[new_row][new_col] == '1')
		return ;
	if (game->map[new_row][new_col] == 'C')
		game->count_c++;
	game->map[game->row_player][game->col_player] = '0';
	game->map[new_row][new_col] = 'P';
	game->row_player = new_row;
	game->col_player = new_col;
	if (i == -1)
		game->player_dir = 'U';
	if (i == 1)
		game->player_dir = 'D';
	if (j == -1)
		game->player_dir = 'L';
	if (j == 1)
		game->player_dir = 'R';
	render_map(game);
}

static void	put_tile_p(int i, int j, t_game *g)
{
	if (g->player_dir == 'R')
			mlx_put_image_to_window(g->mlx, g->win, g->img_p_r, j * T_S, i * T_S);
		if (g->player_dir == 'L')
			mlx_put_image_to_window(g->mlx, g->win, g->img_p_l, j * T_S, i * T_S);
		if (g->player_dir == 'U')
			mlx_put_image_to_window(g->mlx, g->win, g->img_p_u, j * T_S, i * T_S);
		if (g->player_dir == 'D')
			mlx_put_image_to_window(g->mlx, g->win, g->img_p_d, j * T_S, i * T_S);
}

static void	put_on_tile(int i, int j, t_game *g, char c)
{
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img_f, j * T_S, i * T_S);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_w, j * T_S, i * T_S);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, j * T_S, i * T_S);
	if (c == 'E' && (g->count_c == g->total_c))
		mlx_put_image_to_window(g->mlx, g->win, g->img_esc, j * T_S, i * T_S);
	if (c == 'P')
		put_tile_p(i, j, g);
}

static void	draw_tile(int i, int j, t_game *game)
{
	if (game->map[i][j] == 'P')
		put_on_tile(i, j, game, 'P');
	if (game->map[i][j] == '1')
		put_on_tile(i, j, game, '1');
	if (game->map[i][j] == 'C')
		put_on_tile(i, j, game, 'C');
	if (game->map[i][j] == 'E')
		put_on_tile(i, j, game, 'E');
	if (game->map[i][j] == '0')
		put_on_tile(i, j, game, '0');
}

void	render_map(t_game *game)
{
	size_t		i;
	size_t		j;
	static int	count = 0;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->count_c == game->total_c)
				game->map[game->row_escape][game->col_escape] = 'E';
			draw_tile(i, j, game);
			j++;
		}
		i++;
	}
	ft_printf("Move(s) : %d\n", count);
	if (game->row_player == game->row_escape
		&& game->col_player == game->col_escape
		&& game->count_c == game->total_c)
	{
		ft_printf("Congratulation ! You win !\n");
		close_game(game);
	}
	count++;
}
