/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:21 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/19 15:52:39 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"

bool	is_wall(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	double	buffer;

	buffer = 0.05; // small buffer distance to avoid sliding along walls
	if (x - buffer < 0 || x + buffer >= game->map.width
		|| y - buffer < 0 || y + buffer >= game->map.height)
		return (true);
	map_x = (int)x;
	map_y = (int)y;
	if (game->map.grid[map_y][map_x] == '1')
		return (true);
	if (x - buffer < map_x && game->map.grid[map_y][(int)(x - buffer)] == '1')
		return (true);
	if (x + buffer > map_x + 1 && game->map.grid[map_y][(int)(x + buffer)] == '1')
		return (true);
	if (y - buffer < map_y && game->map.grid[(int)(y - buffer)][map_x] == '1')
		return (true);
	if (y + buffer > map_y + 1 && game->map.grid[(int)(y + buffer)][map_x] == '1')
		return (true);
	return (false);
}