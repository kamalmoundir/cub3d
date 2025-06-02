/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:55 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 18:15:56 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

void	draw_vertical_line(t_game *game, int x, t_line line, int color)
{
	int		y;
	int		*buffer;

	buffer = (int *)game->mlx.img_data;
	if (x < 0 || x >= game->mlx.width)
		return ;
	y = line.start;
	while (y <= line.end)
	{
		if (y >= 0 && y < game->mlx.height)
			buffer[y * game->mlx.width + x] = color;
		y++;
	}
}

void	draw_textured_line(t_game *game, int x, t_line *line,
		t_texture *texture)
{
	int				y;
	int				line_height;
	double			step;
	double			tex_pos;
	t_texture_data	tex_data;

	tex_data.texture = texture;
	tex_data.x = calculate_texture_x(game, texture);
	line_height = (int)(game->mlx.height / game->ray.perp_wall_dist);
	step = 1.0 * texture->height / line_height;
	tex_pos = (line->start - game->mlx.height / 2 + line_height / 2) * step;
	y = line->start;
	while (y <= line->end)
	{
		tex_data.y = (int)tex_pos % texture->height;
		if (tex_data.y < 0)
			tex_data.y += texture->height;
		tex_pos += step;
		draw_texture_pixel(game, x, y, &tex_data);
		y++;
	}
}
