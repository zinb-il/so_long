/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:35:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/03 15:58:08 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_extension(char *s)
{
	char	*file_name;

	file_name = ft_strrchr(s, '.');
	if (!file_name || ft_strncmp(file_name, ".ber", 5))
	{
		ft_putstr_fd(ERROR_EXTENTION, 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	*gm;

	if (ac >= 2)
	{
		ft_check_extension(av[1]);
		gm = (t_game *)malloc(sizeof(t_game));
		if (!gm)
		{
			perror("ERROR\n");
			exit(EXIT_FAILURE);
		}
		gm->map = ft_valid_map(av[1]);
		gm = ft_draw_map(gm);
		mlx_hook(gm->window, 17, 0, ft_destroy_window, gm);
		mlx_key_hook(gm->window, ft_key_press, &gm);
		mlx_loop(gm->mlx);
	}
	else
		ft_putstr_fd(ERROR_PARAMETERS, 1);
	return (0);
}
