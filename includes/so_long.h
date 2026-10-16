/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:11:40 by jroh              #+#    #+#             */
/*   Updated: 2025/12/06 11:57:46 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

# define T_S 32

typedef struct s_game
{
	size_t	row_player;
	size_t	col_player;
	size_t	row_escape;
	size_t	col_escape;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_f;
	void	*img_w;
	void	*img_esc;
	void	*img_p_u;
	void	*img_p_d;
	void	*img_p_r;
	void	*img_p_l;
	void	*img_c;
	char	player_dir;
	int		count_c;
	int		total_c;
	size_t	height;
	size_t	width;
}				t_game;
char	**initialize_map(char *filename, t_game *game);
void	error_exit(char *msg);
void	check_map(char **map, t_game *game);
int		check_charset(char c);
char	**copy_map(char **map, t_game *game);
void	initialize_loc(char **map, t_game *game);
int		char_c_exist(char **map, t_game *game);
void	open_window(t_game *game);
void	render_map(t_game *game);
void	move_player(t_game *game, int i, int j);
int		number_of_c(t_game *game);
int		close_game(t_game *game);

#endif
