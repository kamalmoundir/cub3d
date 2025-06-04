/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:13 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/04 12:41:52 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "utils.h"

void	safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_config(t_config *config)
{
	if (config)
	{
		if (config->north_texture)
			safe_free((void **)&config->north_texture);
		if (config->south_texture)
			safe_free((void **)&config->south_texture);
		if (config->east_texture)
			safe_free((void **)&config->east_texture);
		if (config->west_texture)
			safe_free((void **)&config->west_texture);
	}
}
