/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:37 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/23 16:08:38 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"

void	move_player_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_step;

	move_step = game->player.move_speed * game->player.move_forward;
	new_x = game->player.position.x + game->player.direction.x * move_step;
	new_y = game->player.position.y + game->player.direction.y * move_step;
	if (!is_wall(game, new_x, game->player.position.y))
		game->player.position.x = new_x;
	if (!is_wall(game, game->player.position.x, new_y))
		game->player.position.y = new_y;
}

void	move_player_sideways(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_step;

	move_step = game->player.move_speed * game->player.move_sideways;
	new_x = game->player.position.x + game->player.plane.x * move_step;
	new_y = game->player.position.y + game->player.plane.y * move_step;
	if (!is_wall(game, new_x, game->player.position.y))
		game->player.position.x = new_x;
	if (!is_wall(game, game->player.position.x, new_y))
		game->player.position.y = new_y;
}

void	rotate_player(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;
	double	cos_rot;
	double	sin_rot;

	rot_speed = game->player.rot_speed * game->player.rotate;
	cos_rot = cos(rot_speed);
	sin_rot = sin(rot_speed);
	old_dir_x = game->player.direction.x;
	game->player.direction.x = old_dir_x * cos_rot - game->player.direction.y * sin_rot;
	game->player.direction.y = old_dir_x * sin_rot + game->player.direction.y * cos_rot;
	old_plane_x = game->player.plane.x;
	game->player.plane.x = old_plane_x * cos_rot - game->player.plane.y * sin_rot;
	game->player.plane.y = old_plane_x * sin_rot + game->player.plane.y * cos_rot;
}