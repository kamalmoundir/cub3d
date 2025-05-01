/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:31:10 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:18:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int main(void)
{

    if(!validate_input("assets/maps/map1.cub"))
    {
        printf("error");
        return (-1);
    }
    // 1. Load map and config
    char **data_raw = get_raw_lines("assets/maps/map1.cub");
    t_map *map = malloc(sizeof(t_map));
    if(!init_def_map(map))
    {
        return (-1);
    }
    ft_extract_map(data_raw, map);

    t_config *config = malloc(sizeof(t_config));
    if(!init_def_config(config))
    {
        return(-1);
    }
    if (!extract_config(data_raw, config)) 
    {
        printf("Config extraction failed\n");
        return (1);
    }

    // 2. Initialize game and player
    t_game *game = malloc(sizeof(t_game));
    if(!game) return(1);
    if(!init_def_game(game)) return -1;
    t_player *player = malloc(sizeof(t_player));
    if(!player) return 1;
    if(!init_def_player(player)) return -1;
    game->map = map;
    get_player_pos_dir(map, player);
    game->player = player;
    game->config = config;

    // 3. Initialize MLX and start game loop
   /*game->mlx = mlx_init(1500, 1500, "cub3d", false);
    if (!(game->mlx))
        return (1);
    mlx_key_hook(game->mlx, 0, game);
    mlx_loop(game->mlx);
    //mlx_terminate(game->mlx);*/

    // 4. Free resources
    free_config(config);
    free_array(data_raw);
    free_array(map->grid);
    free(map);
    free(player);
    free(game);

    return (0);
}
