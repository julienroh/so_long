/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:31:36 by jroh              #+#    #+#             */
/*   Updated: 2025/12/07 11:42:18 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_loc(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (map[i][j] == 'P')
			{
				game->row_player = i;
				game->col_player = j;
			}
			else if (map[i][j] == 'E')
			{
				game->row_escape = i;
				game->col_escape = j;
			}
		}
		i++;
	}
}

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	return (count);
}

static char	**read_map(char **map, char *filename, int height)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < height)
	{
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = line;
		i++;
	}
	map[height] = NULL;
	close(fd);
	return (map);
}

char	**initialize_map(char *filename, t_game *game)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->height = count_lines(fd);
	close (fd);
	map = malloc(sizeof(char *) * (game->height + 1));
	map = read_map(map, filename, game->height);
	check_map(map, game);
	return (map);
}
