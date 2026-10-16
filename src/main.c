/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:13:58 by jroh              #+#    #+#             */
/*   Updated: 2025/12/06 12:04:03 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (!ft_strncmp(str + len - 4, ".ber", 4))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage : ./so_long map.ber\n");
	if (!has_ber_extension(argv[1]))
		error_exit("Need .ber extension\n");
	game.map = initialize_map(argv[1], &game);
	if (game.map == NULL)
		error_exit("Impossible to open the file\n");
	game.player_dir = 'R';
	game.total_c = number_of_c(&game);
	game.count_c = 0;
	open_window(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
