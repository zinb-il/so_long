/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:06:58 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/04 15:45:42 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_lines(int fd)
{
	int		line;
	char	*c;

	line = 0;
	c = get_next_line(fd);
	while (c)
	{
		free(c);
		c = get_next_line(fd);
		line++;
	}
	return (line);
}

static char	**ft_fill_map(char *file_name, int line)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map)
	{
		perror("ERROR\n");
		exit(EXIT_FAILURE);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\n");
		exit(EXIT_FAILURE);
	}
	while (i < line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

static char	**ft_valid_map_file(char *file_name)
{
	int		fd;
	int		line;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\n");
		exit(EXIT_FAILURE);
	}
	line = ft_get_lines(fd);
	if (!line)
	{
		ft_putstr_fd(ERROR_INVALID_MAP, 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
	map = ft_fill_map(file_name, line);
	return (map);
}

void	ft_map_line(char **map)
{
	int	i;

	i = 1;
	while (map[i] != 0)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
		{
			ft_putstr_fd(ERROR_INVALID_MAP, 1);
			ft_exit_failure(map);
		}
		i++;
	}
}

char	**ft_valid_map(char *file_name)
{
	char	**map;

	map = ft_valid_map_file(file_name);
	ft_map_line(map);
	ft_check_map_elemnts(map);
	return (map);
}
