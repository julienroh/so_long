/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:28:31 by jroh              #+#    #+#             */
/*   Updated: 2025/12/06 12:02:49 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_charset(char c)
{
	if (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0')
		return (1);
	return (0);
}

char	**copy_map(char **map, t_game *game)
{
	size_t	i;
	size_t	j;
	char	**copy_map;

	i = 0;
	copy_map = malloc (sizeof(char *) * (game->height + 1));
	while (i < game->height)
	{
		j = 0;
		copy_map[i] = malloc (sizeof(char) * (game->width + 1));
		while (j < game->width)
		{
			copy_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (copy_map);
}

int	char_c_exist(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	number_of_c(t_game *game)
{
	int		count;
	size_t	j;
	size_t	i;

	i = 0;
	count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
