/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:03 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/22 23:30:05 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

void	draw_wall_slice(t_game *game, int x)
{
	int		line_height;
	t_line	wall_line;
	int		color;

	line_height = (int)(game->mlx.height / game->ray.perpWallDist);
	wall_line.start = -line_height / 2 + game->mlx.height / 2;
	if (wall_line.start < 0)
		wall_line.start = 0;
	wall_line.end = line_height / 2 + game->mlx.height / 2;
	if (wall_line.end >= game->mlx.height)
		wall_line.end = game->mlx.height - 1;
	color = select_wall_color(game, &game->ray);
	draw_vertical_line(game, x, wall_line, color);
}

// to be expanded on later
int	select_wall_color(t_game *game, t_ray *ray)
{
	int		color;
	char	wall_value;

	wall_value = game->map.grid[ray->mapY][ray->mapX];
	if (wall_value == '1') // Standard wall
	{
		if (ray->side == 0) // Red (E/W)
		{
			if (ray->stepX > 0)
				color = 0xFF0000;
			else
				color = 0xCC0000;
		}
		else // Green (N/S)
		{
			if (ray->stepY > 0)
				color = 0x00FF00;
			else
				color = 0x00CC00;
		}
	}
	else
		color = 0x0000FF; // blue for others
	if (ray->side == 1)
		color = (color >> 1) & 8355711; // 50% darker
	return (color);
}