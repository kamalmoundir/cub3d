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

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	*buffer;

	buffer = (int *)game->mlx.img_data;
	y = 0;
	while (y < game->mlx.height)
	{
		x = 0;
		while (x < game->mlx.width)
		{
			if (y < game->mlx.height / 2)
				buffer[y * game->mlx.width + x] = game->ceiling_color;
			else
				buffer[y * game->mlx.width + x] = game->floor_color;
			x++;
		}
		y++;
	}
}