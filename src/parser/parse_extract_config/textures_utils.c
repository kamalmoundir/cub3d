/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:08:42 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 17:00:07 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "game.h"

bool	verify_texture_file(char *texture_path)
{
	int	fd;

	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
