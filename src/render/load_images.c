/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:51 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/16 16:33:29 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		set_error(&game->error, "Failed to load texture", 1);
		return (false);
	}
	texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bits_pixel,
			&texture->size_line, &texture->endian);
	return (true);
}

bool load_all_textures(t_game *game)
{ 
    if(!load_texture(game, &game->textures.north , game->config.north_texture)) 
        return (false);
    if(!load_texture(game, &game->textures.south , game->config.south_texture)) 
        return (false);
    if(!load_texture(game, &game->textures.east , game->config.east_texture)) 
        return (false);
    if(!load_texture(game, &game->textures.west, game->config.west_texture)) 
        return (false);
    return true;   
}
