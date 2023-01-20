/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:44:36 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/03 15:55:33 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_game *g)
{
	mlx_destroy_window(g->mlx, g->window);
	exit(EXIT_FAILURE);
}

static void	ft_image_exit(t_game *g, char c, int i, int j)
{
	int		w;
	int		y;
	void	*img;

	img = NULL;
	w = 0;
	y = 0;
	if (c == EXIT)
		img = mlx_xpm_file_to_image(g->mlx, MAP_EXIT_OPEN, &w, &y);
	if (img == NULL)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(g->mlx, g->window, img, w * j, y * i);
	mlx_destroy_image(g->mlx, img);
}

void	ft_check_exit(t_game *g)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = g->map;
	if (g->coll == 0)
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == EXIT)
					ft_image_exit(g, EXIT, i, j);
				j++;
			}
			i++;
		}
	}
}

void	ft_exit_failure(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	exit(EXIT_FAILURE);
}

void	ft_exit_failure1(t_game *g)
{
	int	i;

	i = 0;
	if (g)
	{
		if (g->map)
		{
			while ((g->map + i))
			{
				free(g->map + i);
				i++;
			}
			free(g->map);
		}
		free(g);
	}
	exit(EXIT_FAILURE);
}
