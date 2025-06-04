/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:13:42 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/04 12:36:51 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/time.h>

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0));
}

int	ft_is_number(const char *s)
{
	char	*str;
	char	*orig;

	if (!s || !*s)
		return (0);
	str = ft_strtrim(s, " ");
	if (!str)
		return (0);
	orig = str;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
		{
			free(orig);
			return (0);
		}
		str++;
	}
	free(orig);
	return (1);
}
