/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:29 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/23 16:08:30 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

bool	init_player(t_player *player)
{
	player->position.x = 2.5;
	player->position.y = 2.5;
	player->direction.x = -1.0;
	player->direction.y = 0.0;
	player->plane.x = 0.0;
	player->plane.x = 0.66;
	player->move_speed = 0.05;
	player->rot_speed = 0.03;
	player->move_forward = 0;
	player->move_sideways = 0;
	player->rotate = 0;
	player->health = 100;
	player->stamina = 100;
	player->has_key = false;
	player->score = 0;
	return (true);
}