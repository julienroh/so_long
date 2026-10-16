/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:11:24 by jroh              #+#    #+#             */
/*   Updated: 2025/12/07 11:44:13 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rectangular_check(char **map, t_game *game)
{
	size_t	i;

	i = 0;
	if (game->width == game->height)
		error_exit("Map not rectangular\n");
	while (i < game->height)
	{
		if (ft_strlen(map[i]) != game->width)
			error_exit("Map not rectangular\n");
		i++;
	}
}

static void	surrounded_check(char **map, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		if (map[i][0] != '1')
			error_exit("Map not surrounded by walls\n");
		if (map[i][game->width - 1] != '1')
			error_exit("Map not surrounded by walls\n");
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (map[0][i] != '1')
			error_exit("Map not surrounded by walls\n");
		if (map[game->height - 1][i] != '1')
			error_exit("Map not surrounded by walls\n");
		i++;
	}
}

static void	char_check(char **map, t_game *game, int count_e, int count_p)
{
	size_t	i;
	size_t	j;
	int		count_c;

	i = 0;
	count_c = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == 'C')
				count_c++;
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'E')
				count_e++;
			if (!check_charset(map[i][j]))
				error_exit("Map contains forbidden component(s)\n");
			j++;
		}
		i++;
	}
	if (count_c < 1 || count_e != 1 || count_p != 1)
		error_exit("Need less or more component(s)\n");
}

// static void	flood_fill(char **copy, size_t row, size_t col, t_game *game)
// {
// 	int	row_int;
// 	int	col_int;

// 	row_int = (int)row;
// 	col_int = (int)col; // A SUPPRIMER A LECOLE. ATTENTION AUSSI AU MAKEFILE DE PRINTF QUI A ETE MODIFIE
// 	if (row_int < 0 || col_int < 0 || row >= game->height || row >= game->width)
// 		return ;
// 	if (copy[row][col] == 'F' || copy[row][col] == '1')
// 		return ;
// 	copy[row][col] = 'F';
// 	flood_fill (copy, row, col + 1, game);
// 	flood_fill (copy, row, col - 1, game);
// 	flood_fill (copy, row + 1, col, game);
// 	flood_fill (copy, row - 1, col, game);
// }

void	check_map(char **map, t_game *game)
{
	char	**copy;
	int		count_p;
	int		count_e;

	count_p = 0;
	count_e = 0;
	game->width = ft_strlen(map[0]);
	copy = copy_map(map, game);
	rectangular_check(map, game);
	surrounded_check(map, game);
	char_check(map, game, count_e, count_p);
	initialize_loc(map, game);
	// flood_fill(copy, game->row_player, game->col_player, game);
	// if (copy[game->row_escape][game->col_escape] != 'F'
	// 	|| char_c_exist(copy, game))
	// 	error_exit("No valid path for this map\n");
	free(copy);
}
