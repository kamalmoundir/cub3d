/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:55 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/22 23:29:56 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

void	draw_vertical_line(t_game *game, int x, t_line line, int color)
{
	int		y;
	int		*buffer;

	buffer = (int *)game->mlx.img_data;
	if (x < 0 || x >= game->mlx.width)
		return ;
	y = line.start;
	while (y <= line.end)
	{
		if (y >= 0 && y < game->mlx.height)
			buffer[y * game->mlx.width + x] = color;
		y++;
	}
}