/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 17:05:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gnl.h"
#include "map.h"
#include "player.h"
#include "types.h"

int	get_map_hight(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		i++;
	}
	return (i);
}

int	get_map_hight1(t_map *map)
{
	int	i;

	i = 0;
	while (map->copy_grid[i])
	{
		i++;
	}
	return (i);
}

int	get_map_width(t_map *map)
{
	int				i;
	unsigned int	max_width;

	if (!map)
		return (-1);
	i = -1;
	max_width = 0;
	while (map->grid[++i])
	{
		if (max_width < ft_strlen(map->grid[i]))
			max_width = ft_strlen(map->grid[i]);
	}
	return (max_width);
}

void	path_finder(char **map, int x, int y)
{
	(void)x;
	(void)y;
	(void)map;
	if (map == NULL)
		return ;
	if (x < 0 || x > (int)ft_strlen(map[y]) || y < 0 || !map[y]
		|| map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == ' ')
		return ;
	map[y][x] = 'V';
	path_finder(map, x + 1, y);
	path_finder(map, x - 1, y);
	path_finder(map, x, y + 1);
	path_finder(map, x, y - 1);
}

bool	get_player_pos_dir(t_map *map, t_player *player)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
			{
				if (found)
					return (false);
				player->position.x = j + 0.5;
				player->position.y = i + 0.5;
				player->init_dir = map->grid[i][j];
				found = 1;
			}
		}
	}
	return (true);
}
