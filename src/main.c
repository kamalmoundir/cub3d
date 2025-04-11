/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:31:10 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:27 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
    int fd;
    char **map;
    
    int i=0;
    t_cub3d *game;
    game = malloc(sizeof(t_cub3d));
    if (!game)
        return (1);

    fd = open("assets/maps/map1.cub", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    map = array_map(fd);
    if (!map)
    {
        close(fd);
        return (1);
    }
    if(check_empty_line(map) == 1)
        printf("ERROR: empty line \n");
    if(check_caracters(map))
        printf("ERROR : caracters no valid ::: -%d-\n",check_caracters(map));
    if(check_multi_players(map))
        printf("ERROR : multiple players\n");
    if(check_borders(map))
        printf("ERROR : BORDER line : %d\n",check_borders(map));
    printf("map hight : %d\n",get_map_hight(map));
    printf("map width : %d\n",get_map_width(map));
    char **map_copy = copy_map(map,get_map_hight(map));
    
    while (map[i])
    {
        printf("%s", map[i]);
        printf("\n");
        free(map[i]);
        i++;
    }
    t_player player =get_player_pos_dir(map_copy);
   printf("X= %d      Y=%d  init directio= %c \n",player.pos_x,player.pos_y,player.init_dir);
   path_finder(map_copy,player.pos_x,player.pos_y);
   if(check_unreacheble_area(map_copy))
    {
        printf(" error unreacheble eara \n\n");
    }
        i=0;
    while (map_copy[i])
    {
        printf("%s", map_copy[i]);
        printf("\n");
        free(map_copy[i]);
        i++;
    }
   
    free(map_copy);
    free(map);
    close(fd);
  game->mlx = mlx_init(1500, 1500, "cub3d", false);
	if (!(game->mlx))
		return (1);
        mlx_key_hook(game->mlx, 0, game);
        mlx_loop(game->mlx);
        mlx_terminate(game->mlx);
    free(game);

    return (0);
}