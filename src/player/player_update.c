/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:09:17 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/23 16:09:18 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "utils.h"

void	update_player(t_game *game)
{
	update_movement_speed(game);
	if (game->player.move_forward != 0)
		move_player_forward(game);
	if (game->player.move_sideways != 0)
		move_player_sideways(game);
	if (game->player.rotate != 0)
		rotate_player(game);	
}

void	update_movement_speed(t_game *game)
{
	double	current_time;

	current_time = get_time_ms();
	game->frame_time = current_time - game->last_frame_time;
	game->last_frame_time = current_time;

	game->player.move_speed = game->frame_time * 0.005;
	game->player.rot_speed = game->frame_time * 0.003;
}
