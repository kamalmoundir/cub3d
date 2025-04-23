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
	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map.width || map_y < 0 || map_y >= game->map.height)
		return (true);
	return (game->map.grid[map_y][map_x] != 0);
}