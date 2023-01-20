/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:45:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 22:03:26 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_i(t_game *g, int r, int u)
{
	if (r && u)
		return (g->p_x - 1);
	else if (r && !u)
		return (g->p_x + 1);
	else if (!r)
		return (g->p_x);
	return (0);
}

int	ft_get_j(t_game *g, int r, int u)
{
	if (!r && u)
		return (g->p_y - 1);
	else if (!r && !u)
		return (g->p_y + 1);
	else if (r)
		return (g->p_y);
	return (0);
}

t_game	*ft_update_map(t_game *g, int i, int j)
{
	ft_draw_image(g, SPACE, g->p_x, g->p_y);
	ft_draw_image(g, PLAY, i, j);
	g->mv++;
	*(*(g->map + i) + j) = PLAY;
	*(*(g->map + g->p_x) + g->p_y) = SPACE;
	g->p_x = i;
	g->p_y = j;
	return (g);
}

t_game	*ft_move_up_down(t_game *g, int r, int u)
{
	int		i;
	int		j;
	char	c;
	char	**map;

	i = ft_get_i(g, r, u);
	j = ft_get_j(g, r, u);
	map = g->map;
	c = map[i][j];
	if (c == ENMI)
		ft_game_over(g);
	if (c == SPACE || c == COLL || (c == EXIT && !g->coll))
	{
		g = ft_update_map(g, i, j);
		ft_putstr_window(g);
	}
	if (c == EXIT && !g->coll)
		ft_destroy_window (g);
	if (c == COLL)
		g->coll--;
	if (g->coll == 0)
		ft_check_exit(g);
	return (g);
}

int	ft_key_press(int key_code, t_game **g)
{
	if (key_code == KEY_ESC || key_code == KEY_ESC1)
		ft_destroy_window(*g);
	else if (key_code == KEY_UP || key_code == KEY_UP1)
		*g = ft_move_up_down(*g, 1, 1);
	else if (key_code == KEY_DOWN || key_code == KEY_DOWN1)
		*g = ft_move_up_down(*g, 1, 0);
	else if (key_code == KEY_LEFT || key_code == KEY_LEFT1)
		*g = ft_move_up_down(*g, 0, 1);
	else if (key_code == KEY_RIGHT || key_code == KEY_RIGHT1)
		*g = ft_move_up_down(*g, 0, 0);
	return (0);
}
