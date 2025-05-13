/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:42:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 14:00:20 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "types.h"
#include "player.h"

bool initialize_player(t_map *map, t_player *player)
{

    if(!get_player_pos_dir(map,player))
        return (false);
    if(player->init_dir == 'N')
    {
        player->direction.x=0;
        player->direction.y=-1;
    }
    else if(player->init_dir == 'S')
    {
        player->direction.x = 0;
        player->direction.y = 1;
    }
    else if(player->init_dir == 'E')
    {
        player->direction.x = 1;
        player->direction.y = 0;
    }
    else if(player->init_dir == 'W')
    {
        player->direction.x = -1;
        player->direction.y = 0;
    }
    return (true);
}