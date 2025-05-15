/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:21 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/23 16:08:22 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"

bool	is_wall(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	double	buffer;

	buffer = 0.1; // small buffer distance to avoid sliding along walls
	if (x - buffer < 0 || x + buffer >= game->map.width
		|| y - buffer < 0 || y + buffer >= game->map.height)
		return (true);
	map_x = (int)x;
	map_y = (int)y;
	if (game->map.grid[map_y][map_x] != '0')
		{printf("%c\n",game->map.grid[map_y][map_x]);return (true);}
	if (x - buffer < map_x && game->map.grid[map_y][(int)(x - buffer)] != '0')
		{printf("2\n");return (true);}
	if (x + buffer > map_x + 1 && game->map.grid[map_y][(int)(x + buffer)] != '0')
		{printf("3\n");return (true);}
	if (y - buffer < map_y && game->map.grid[(int)(y - buffer)][map_x] != '0')
		{printf("4\n");return (true);}
	if (y + buffer > map_y + 1 && game->map.grid[(int)(y + buffer)][map_x] != '0')
	{printf("5");return (true);}
	return (false);
}