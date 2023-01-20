/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_elemnts_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:41:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/01 21:20:24 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_check_map_elemnt(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
	{
		ft_putstr_fd(ERROR_ALLOCATION, 1);
		exit(EXIT_FAILURE);
	}
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E' \
				&& map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'S')
			{
				ft_putstr_fd(ERROR_INVALID_MAP, 1);
				ft_exit_failure(map);
			}
			j++;
		}
		i++;
	}
}

static void	ft_check_cpe(int c, int p, int e, int s)
{
	int	i;

	i = 0;
	if (e == 0)
	{
		ft_putstr_fd(ERROR_EXIT_MAP, 1);
		i = 1;
	}
	if (p != 1)
	{
		ft_putstr_fd(ERROR_PLAYER_MAP, 1);
		i = 1;
	}
	if (c == 0)
	{
		ft_putstr_fd(ERROR_COLLECT_MAP, 1);
		i = 1;
	}
	if (s == 0)
	{
		ft_putstr_fd(ERROR_ENMIES, 1);
		i = 1;
	}
	if (i)
		exit(EXIT_FAILURE);
}

static void	ft_count_cpe(char **map)
{
	int	i;
	int	p;
	int	c;
	int	e;
	int	s;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	s = 0;
	while (map[i] != 0)
	{
		e += (int)ft_count_char(map[i], EXIT);
		p += (int)ft_count_char(map[i], PLAY);
		c += (int)ft_count_char(map[i], COLL);
		s += (int)ft_count_char(map[i], ENMI);
		i++;
	}
	ft_check_cpe(c, p, e, s);
}

static void	ft_check_map_wall(char **map)
{
	int		i;
	size_t	j;

	i = 1;
	if (!map)
	{
		ft_putstr_fd(ERROR_ALLOCATION, 1);
		exit(EXIT_FAILURE);
	}
	while (map[i] != 0)
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_putstr_fd(ERROR_INVALID_WALL, 1);
			ft_exit_failure(map);
		}
		++i;
	}
	if (ft_count_char(map[i - 1], '1') != ft_strlen(map[i - 1])
		|| ft_count_char(map[0], '1') != ft_strlen(map[0]))
	{
		ft_putstr_fd(ERROR_INVALID_WALL, 1);
		ft_exit_failure(map);
	}
}

void	ft_check_map_elemnts(char **map)
{
	ft_check_map_elemnt(map);
	ft_check_map_wall(map);
	ft_count_cpe(map);
}
