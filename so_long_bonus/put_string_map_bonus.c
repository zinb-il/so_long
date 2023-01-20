/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:02:50 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 18:28:19 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr_window(t_game *g)
{
	char	*msg;
	char	*number;
	int		i;

	i = 0;
	while (i < g->map_x)
	{
		ft_draw_image(g, SPACE, -1, i);
		i++;
	}
	number = ft_itoa(g->mv);
	msg = ft_strjoin("Le total des mouvements : ", number);
	mlx_string_put(g->mlx, g->window, 5, 15, 0x000000, msg);
	free (number);
	free(msg);
}
