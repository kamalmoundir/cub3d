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

void	render_frame(t_game *game)
{
	clear_buffer(game);
	if (!cast_all_rays(game))
	{
		ft_printf("DEBUG: Error while casting rays\n");
		return ;
	}
	draw_floor_ceiling(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
}

bool	cast_all_rays(t_game *game)
{
	int	x;

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
		draw_wall_slice(game, x);
		x++;
	}
	return (true);
}