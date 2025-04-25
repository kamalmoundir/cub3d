/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:40 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/22 23:29:41 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

void	clear_buffer(t_game *game)
{
	int	i;
	int	total_pixels;
	int	*buffer;

	buffer = (int *)game->mlx.img_data;
	total_pixels = game->mlx.width * game->mlx.height;
	i = 0;
	while (i < total_pixels)
	{
		buffer[i] = 0;
		i++;
	}
}

void	draw_floor_ceiling(t_game *game, t_line *wall_lines)
{
	int	x;
	int	y;
	int	*buffer;
	int	index;
	int	wall_start;
	int	wall_end;

	if (!wall_lines || !game->mlx.img_data)
		return ;
	buffer = (int *)game->mlx.img_data;
	x = 0;
	while (x < game->mlx.width)
	{
		wall_start = wall_lines[x].start;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = wall_lines[x].end;
		if (wall_end >= game->mlx.height)
			wall_end = game->mlx.height - 1;
		y = 0;
		while (y < wall_start)
		{
			index = y * game->mlx.width + x;
			buffer[index] = game->ceiling_color;
			y++;
		}
		y = wall_end + 1;
		while (y < game->mlx.height)
		{
			index = y * game->mlx.width + x;
			buffer[index] = game->floor_color;
			y++;
		}
		x++;
	}
}