/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:36:44 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:41:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "game.h"
#include "types.h"
#include <stdlib.h>

static int	is_valid_color(int r, int g, int b)
{
	return (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}

int	parse_color(char *line, t_color *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		if (rgb)
			free_array(rgb);
		return (0);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	if (!is_valid_color(r, g, b))
		return (0);
	color->r = r;
	color->g = g;
	color->b = b;
	return (1);
}

int	parse_texture_path(char *line, char **texture_path)
{
	char	*path;

	while (*line == ' ' || *line == '\t')
		line++;
	path = ft_strdup(line);
	if (!path)
		return (0);
	*texture_path = path;
	return (1);
}

int	parse_config_line(char *line, t_config *config)
{
	printf("line: %s\n", line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_texture_path(line + 3, &config->north_texture));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_texture_path(line + 3, &config->south_texture));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture_path(line + 3, &config->west_texture));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture_path(line + 3, &config->east_texture));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line + 2, &config->floor_color));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line + 2, &config->ceiling_color));
	return (0);
}

bool	validate_config(t_config *config)
{
	if (!config->north_texture || !config->south_texture
		|| !config->east_texture || !config->west_texture)
		return (printf("1\n"), false);
	if (!is_valid_color(config->floor_color.r, config->floor_color.g,
			config->floor_color.b) || !is_valid_color(config->ceiling_color.r,
			config->ceiling_color.g, config->ceiling_color.b))
		return (printf("2\n"), false);
	if (!verify_texture_file(config->north_texture)
		|| !verify_texture_file(config->south_texture)
		|| !verify_texture_file(config->east_texture)
		|| !verify_texture_file(config->west_texture))
		return (printf("3\n"), false);
	return (true);
}
