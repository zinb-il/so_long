/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_elemnts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:41:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/03/23 22:48:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				&& map[i][j] != 'C' && map[i][j] != 'P')
			{
				ft_putstr_fd(ERROR_INVALID_MAP, 1);
				ft_exit_failure(map);
			}
			j++;
		}
		i++;
	}
}

static void	ft_check_cpe(int c, int p, int e)
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
	if (i)
		exit(EXIT_FAILURE);
}

static void	ft_count_cpe(char **map)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (map[i] != 0)
	{
		e += (int)ft_count_char(map[i], EXIT);
		p += (int)ft_count_char(map[i], PLAY);
		c += (int)ft_count_char(map[i], COLL);
		i++;
	}
	ft_check_cpe(c, p, e);
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
