/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:02:50 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/03 15:51:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_window(t_game *g)
{
	char	*msg;
	char	*number;

	number = ft_itoa(g->mv);
	msg = ft_strjoin("Le total des mouvements : ", number);
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	free (number);
	free(msg);
}
