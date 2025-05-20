/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:09:24 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/20 16:05:36 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

static int	ft_isspace(int c)
{
	if (c == '\r' || c == '\f' || c == ' ' || c == '\n' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	is_empty_line(const char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

bool is_map_line(const char *line)
{
	int i;

	i = 0;
	if (is_empty_line(line))
		return (false);
	else
	{
		while (line[i])
		{
			if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
				&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
				&& line[i] != ' ')
				return (false);
			i++;
		}
	}
	return (true);
}
void	free_array(char **str)
{
	int	i;

	i = 0;
	if(str && **str)
	{
	while (str[i])
	{
		safe_free((void **)&str[i]);
		i++;
	}
	safe_free((void **)&str);
}
}

char	**copy_map(char **map, int raws)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (raws + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}