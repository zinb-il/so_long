/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 22:02:37 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"

// Define Errors Messages
# define ERROR_ALLOCATION "ERROR\n : une erreur inconue s\'est produit\n"
# define ERROR_ENMIES "ERROR\n : le map doit contenir au moins un ennemie\n"
# define ERROR_PARAMETERS "ERROR\nles paramètres passés sont incorrects\n"
# define ERROR_EXTENTION "ERROR\nl\'extension choisie est incorrecte\n"
# define ERROR_INVALID_MAP "ERROR\n : invalid map\n"
# define ERROR_INVALID_WALL "ERROR\n : les mures de votre map sont invalides\n"
# define ERROR_EXIT_MAP "ERROR\n : la map doit contenir au moins une sortie\n"
# define ERROR_COLLECT_MAP "ERROR\n : la map doit contenir au moins une item\n"
# define ERROR_PLAYER_MAP "ERROR\n : la map doit contenir au maximum un joueur\n"

//Define map images
# define MAP_PLAYER "images/mermaid.xpm"
# define MAP_COLLECTE "images/shell.xpm"
# define MAP_COLL_RIGHT "images/shell-right.xpm"
# define MAP_COLL_LEFT "images/shell-left.xpm"
# define MAP_COLL_DOWN "images/shell-down.xpm"
# define MAP_WALL "images/wall.xpm"
# define MAP_SPACE "images/space.xpm"
# define MAP_EXIT "images/exit-close.xpm"
# define MAP_EXIT_OPEN "images/exit-open.xpm"
# define MAP_ENMMIE "images/sprite.xpm"

//Define map elements
# define SCL_X 64
# define SCL_Y 64
# define COLL 'C'
# define PLAY 'P'
# define WALL '1'
# define EXIT 'E'
# define EXIT_OPEN 'E'
# define SPACE '0'
# define ENMI 'S'

//Key Code
# define KEY_ESC 53
# define KEY_ESC1 12
# define KEY_UP 13
# define KEY_UP1 126
# define KEY_DOWN 1
# define KEY_DOWN1 125
# define KEY_LEFT 0
# define KEY_LEFT1 123
# define KEY_RIGHT 2
# define KEY_RIGHT1 124

//Define Game Struct
typedef struct so_long
{
	char	**map;
	int		coll;
	int		map_x;
	int		map_y;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*window;
	int		loop;
	int		s_loop;
	int		mv;
}t_game;

void	ft_display_map(char **t);
void	ft_exit_failure(char **map);
void	ft_game_over(t_game *g);
void	ft_exit_failure1(t_game *g);
void	ft_check_exit(t_game *g);
void	ft_putstr_window(t_game *g);
int		ft_destroy_window(t_game *g);
int		ft_moves(t_game **g);
int		ft_get_j(t_game *g, int r, int u);
int		ft_get_i(t_game *g, int r, int u);
int		ft_key_press(int key_code, t_game **g);
char	**ft_valid_map(char *file_name);
void	ft_check_map_elemnts(char **map);
t_game	*ft_draw_map(t_game *game);
t_game	*ft_move_sinenlr(t_game *g, int i, int j, int s);
t_game	*ft_move_sinenud(t_game *g, int i, int j, int s);
t_game	*ft_move_up_down(t_game *g, int r, int u);
t_game	*ft_update_map(t_game *g, int i, int j);
void	ft_draw_image(t_game *g, char c, int i, int j);

#	endif