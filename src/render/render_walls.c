/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:03 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 18:16:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"

t_texture	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->direction.x > 0)
			return (&game->textures.west);
		else
			return (&game->textures.east);
	}
	else
	{
		if (ray->direction.y > 0)
			return (&game->textures.north);
		else
			return (&game->textures.south);
	}
}

void	calculate_wall_dimensions(t_game *game, int *line_height,
		t_line *wall_line)
{
	*line_height = (int)(game->mlx.height / game->ray.perp_wall_dist);
	wall_line->start = -(*line_height) / 2 + game->mlx.height / 2;
	if (wall_line->start < 0)
		wall_line->start = 0;
	wall_line->end = (*line_height) / 2 + game->mlx.height / 2;
	if (wall_line->end >= game->mlx.height)
		wall_line->end = game->mlx.height - 1;
}

int	calculate_texture_x(t_game *game, t_texture *texture)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.side == 0)
		wall_x = game->player.position.y + game->ray.perp_wall_dist
			* game->ray.direction.y;
	else
		wall_x = game->player.position.x + game->ray.perp_wall_dist
			* game->ray.direction.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if ((game->ray.side == 0 && game->ray.direction.x > 0)
		|| (game->ray.side == 1 && game->ray.direction.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_texture_pixel(t_game *game, int x, int y, t_texture_data *tex_data)
{
	int	color;
	int	pos;

	pos = tex_data->texture->height * tex_data->y + tex_data->x;
	color = tex_data->texture->data[pos];
	if (game->ray.side == 1)
		color = (color >> 1) & 8355711;
	*(unsigned int *)(game->mlx.img_data + (y * game->mlx.line_len + x
				* (game->mlx.bpp / 8))) = color;
}

void	draw_wall_slice(t_game *game, int x)
{
	int			line_height;
	t_line		wall_line;
	t_texture	*texture;

	calculate_wall_dimensions(game, &line_height, &wall_line);
	texture = select_wall_texture(game, &game->ray);
	draw_textured_line(game, x, &wall_line, texture);
}
