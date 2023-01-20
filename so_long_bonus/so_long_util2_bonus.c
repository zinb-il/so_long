/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:50:25 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 17:20:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_game_over(t_game *g)
{
	ft_putstr_fd("game over :( :( :( !!!\n", 1);
	ft_destroy_window(g);
}

void	ft_draw_sprite(t_game *g, char c, int i, int j)
{
	int		w;
	int		y;
	void	*img;

	img = NULL;
	if (c == 'D')
		img = mlx_xpm_file_to_image(g->mlx, MAP_COLL_DOWN, &w, &y);
	else if (c == 'R')
		img = mlx_xpm_file_to_image(g->mlx, MAP_COLL_RIGHT, &w, &y);
	else if (c == 'L')
		img = mlx_xpm_file_to_image(g->mlx, MAP_COLL_LEFT, &w, &y);
	else
		img = mlx_xpm_file_to_image(g->mlx, MAP_COLLECTE, &w, &y);
	if (img == NULL)
	{
		perror("Error\n");
		ft_exit_failure1(g);
	}
	mlx_put_image_to_window(g->mlx, g->window, img, w * j, y * (i + 1));
	mlx_destroy_image(g->mlx, img);
}

static int	ft_move_coll(t_game *g, int s)
{
	int			i;
	int			j;
	char		**map;

	map = g->map ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((s % 4 == 0) && map[i][j] == COLL)
				ft_draw_sprite(g, 'U', i, j);
			else if ((s % 4 == 1) && map[i][j] == COLL)
				ft_draw_sprite(g, 'R', i, j);
			else if ((s % 4 == 2) && map[i][j] == COLL)
				ft_draw_sprite(g, 'D', i, j);
			else if ((s % 4 == 3) && map[i][j] == COLL)
				ft_draw_sprite(g, 'L', i, j);
			j++;
		}
		i++;
	}
	s++;
	return (s);
}

static t_game	*ft_move_enmmi(t_game *g, int s)
{
	int			i;
	int			j;
	int			t;

	i = 0;
	t = 0;
	while (*(g->map + i))
	{
		j = 0;
		while (*(*(g->map + i) + j))
		{
			if (*(*(g->map + i) + j) == ENMI)
			{
				if (t % 2)
					g = ft_move_sinenlr(g, i, j, s);
				else
					g = ft_move_sinenud(g, i, j, s);
				t++;
			}
			j++;
		}
		i++;
	}
	return (g);
}

int	ft_moves(t_game **g)
{
	static int	s;

	if (!s || s > 4)
		s = 1;
	if ((*g)->loop < 8000)
	{
		(*g)->loop++;
		return (0);
	}
	s = ft_move_coll(*g, s);
	*g = ft_move_enmmi(*g, s);
	(*g)->loop = 0;
	return (0);
}
