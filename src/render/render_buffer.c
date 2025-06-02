/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:40 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 17:31:11 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"

static void	fill_ceiling(t_game *game, int *buf, int x, int start)
{
	int	y;
	int	index;
	int	color;

	color = rgb_to_int(game->config.ceiling_color);
	y = 0;
	while (y < start)
	{
		index = y * game->mlx.width + x;
		buf[index] = color;
		y++;
	}
}

static void	fill_floor(t_game *game, int *buf, int x, int start)
{
	int	index;
	int	color;

	color = rgb_to_int(game->config.floor_color);
	while (start < game->mlx.height)
	{
		index = start * game->mlx.width + x;
		buf[index] = color;
		start++;
	}
}

static void	fill_column(t_game *game, int *buf, int x, t_line wall)
{
	int	start;
	int	end;

	start = wall.start;
	if (start < 0)
		start = 0;
	end = wall.end;
	if (end >= game->mlx.height)
		end = game->mlx.height - 1;
	fill_ceiling(game, buf, x, start);
	fill_floor(game, buf, x, end + 1);
}

void	draw_floor_ceiling(t_game *game, t_line *wall_lines)
{
	int	x;
	int	*buf;

	if (!wall_lines || !game->mlx.img_data)
		return ;
	x = 0;
	buf = (int *)game->mlx.img_data;
	while (x < game->mlx.width)
	{
		fill_column(game, buf, x, wall_lines[x]);
		x++;
	}
}
