/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:36:02 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 17:29:22 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define  PLAYER_H

#include "types.h"

typedef struct s_player
{
    t_vec2        position;
    t_vec2        direction;
    t_vec2        plane;
    char        init_dir;
    double      move_speed;     // Movement speed
    double      rot_speed;      // Rotation speed
} t_player;

//initialize player struct with default values
bool	init_def_player(t_player *player);

bool	get_player_pos_dir(t_map *map, t_player *player);
#endif