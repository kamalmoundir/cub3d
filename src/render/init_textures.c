/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:48:24 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 16:53:15 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	init_texture_default(t_texture *texture)
{
	if (!texture)
		return (false);
	texture->bits_pixel = 32;
	texture->data = 0;
	texture->width = 64;
	texture->height = 64;
	texture->size_line = 0;
	texture->endian = 0;
	texture->img = NULL;
	return (true);
}

bool	init_all_textures_default(t_textures *txt)
{
	if (!txt)
		return (false);
	if (!init_texture_default(&txt->north))
	{
		return (false);
	}
	if (!init_texture_default(&txt->south))
	{
		return (false);
	}
	if (!init_texture_default(&txt->east))
	{
		return (false);
	}
	if (!init_texture_default(&txt->west))
	{
		return (false);
	}
	return (true);
}
