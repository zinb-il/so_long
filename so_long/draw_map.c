/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:29:56 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/03 15:54:51 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_image(t_game *g, char c, int i, int j)
{
	int		w;
	int		y;
	void	*img;

	img = NULL;
	w = 0;
	y = 0;
	if (c == COLL)
		img = mlx_xpm_file_to_image(g->mlx, MAP_COLLECTE, &w, &y);
	else if (c == PLAY)
		img = mlx_xpm_file_to_image(g->mlx, MAP_PLAYER, &w, &y);
	else if (c == WALL)
		img = mlx_xpm_file_to_image(g->mlx, MAP_WALL, &w, &y);
	else if (c == EXIT)
		img = mlx_xpm_file_to_image(g->mlx, MAP_EXIT, &w, &y);
	else
		img = mlx_xpm_file_to_image(g->mlx, MAP_SPACE, &w, &y);
	if (img == NULL)
	{
		perror("Error\n");
		ft_exit_failure1(g);
	}
	mlx_put_image_to_window(g->mlx, g->window, img, w * j, y * i);
	mlx_destroy_image(g->mlx, img);
}

static void	ft_put_images(t_game *g)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = g->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_draw_image(g, map[i][j], i, j);
			j++;
		}
		i++;
	}
}

static t_game	*ft_init_map(t_game *g)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = g->map;
	g->coll = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLL)
				g->coll++;
			if (map[i][j] == PLAY)
			{
				g->p_x = i;
				g->p_y = j;
			}
			j++;
		}
		i++;
	}
	g->map_y = i;
	return (g);
}

t_game	*ft_draw_map(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g = ft_init_map(g);
	g->mv = 0;
	g->map_x = ft_strlen(*(g->map + i));
	i = g->map_x * SCL_X;
	j = g->map_y * SCL_Y;
	g->mlx = mlx_init();
	g->window = mlx_new_window(g->mlx, i, j, "SO LONG");
	ft_putstr_window(g);
	ft_put_images(g);
	return (g);
}
