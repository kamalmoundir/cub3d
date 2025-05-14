/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:47 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/22 23:29:48 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"
#include "ray.h"
#include "utils.h"
#include "config.h"

void	render_frame(t_game *game)
{
	t_line	*wall_lines;

	// clear_buffer(game);
	wall_lines = malloc(sizeof(t_line) * game->mlx.width);
	if (!wall_lines)
		return ;
	if (!cast_all_rays(game, wall_lines))
	{
		safe_free((void **)&wall_lines);
		ft_printf("DEBUG: Error while casting rays\n");
		return ;
	}
	draw_floor_ceiling(game, wall_lines);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
	safe_free((void **)&wall_lines);
}

bool	cast_all_rays(t_game *game, t_line *wall_lines)
{
	int	x;
	int	line_height;

	x = 0;
	while (x < game->mlx.width)
	{
		init_ray(&game->player, &game->ray, x, game->mlx.width);
		if (!perform_dda(&game->map, &game->ray, &game->error))
		{
			set_error(&game->error, "Ray casting failed", EXIT_FAILURE);
			game->running = false;
			return (false);
		}
		calculate_wall_distance(&game->player, &game->ray);
		if (game->ray.perpWallDist < 0.0001)
			game->ray.perpWallDist = 0.0001;
		line_height = (int)(game->mlx.height / game->ray.perpWallDist);
		wall_lines[x].start = -line_height / 2 + game->mlx.height / 2;
		wall_lines[x].end = line_height / 2 + game->mlx.height / 2;
		draw_wall_slice(game, x);
		x++;
	}
	return (true);
}