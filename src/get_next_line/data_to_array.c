/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:22:44 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 17:15:40 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gnl.h"

int	get_number_line_file(char *filepath)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

char	**array_map(int fd, int size)
{
	char	**map;
	int		i;
	char	*line;

	i = 0;
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
		if (!map[i])
		{
			while (i >= 0)
				free(map[i--]);
			return (free(map), NULL);
		}
		ft_strlcpy_gnl(map[i], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (close(fd), map);
}
