/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_enmmies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:33:26 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 20:50:40 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_get_s_i(int i, int r, int u)
{
	if (r && u)
		return (i - 1);
	else if (r && !u)
		return (i + 1);
	else if (!r)
		return (i);
	return (0);
}

static int	ft_get_s_j(int j, int r, int u)
{
	if (!r && u)
		return (j - 1);
	else if (!r && !u)
		return (j + 1);
	else if (r)
		return (j);
	return (0);
}

static t_game	*ft_udpate_mapen(t_game *g, int *t, int r, int u)
{
	int		x;
	int		y;
	char	c;

	x = ft_get_s_i(t[0], r, u);
	y = ft_get_s_j(t[1], r, u);
	c = *(*(g->map + x) + y);
	if (c == SPACE)
	{
		ft_draw_image(g, ENMI, x, y);
		ft_draw_image(g, SPACE, t[0], t[1]);
		*(*(g->map + x) + y) = ENMI;
		*(*(g->map + t[0]) + t[1]) = SPACE;
	}
	return (g);
}

t_game	*ft_move_sinenud(t_game *g, int i, int j, int s)
{
	int			t[2];

	t[0] = i;
	t[1] = j;
	if (s % 4 == 0)
		g = ft_udpate_mapen(g, t, 1, 1);
	else if (s % 4 == 1)
		g = ft_udpate_mapen(g, t, 1, 0);
	else if (s % 4 == 2)
		g = ft_udpate_mapen(g, t, 1, 1);
	else if (s % 4 == 3)
		g = ft_udpate_mapen(g, t, 1, 0);
	return (g);
}

t_game	*ft_move_sinenlr(t_game *g, int i, int j, int s)
{
	int			t[2];

	t[0] = i;
	t[1] = j;
	if (s % 4 == 0)
		g = ft_udpate_mapen(g, t, 0, 1);
	else if (s % 4 == 1)
		g = ft_udpate_mapen(g, t, 0, 0);
	else if (s % 4 == 2)
		g = ft_udpate_mapen(g, t, 0, 1);
	else if (s % 4 == 3)
		g = ft_udpate_mapen(g, t, 0, 0);
	return (g);
}
