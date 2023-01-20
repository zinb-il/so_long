SRCS = main.c valid_map_bonus.c valid_map_elemnts_bonus.c draw_map_bonus.c hook_map_bonus.c so_long_util_bonus.c put_string_map_bonus.c so_long_util2_bonus.c sprite.c hook_enmmies_bonus.c

LIBFT_SRCS  = libft/ft_strlen.c libft/ft_bzero.c libft/ft_strlcat.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_count_char.c libft/get_next_line.c 

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDES =  mlx/

LINKS =  mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME) :
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(SRCS) $(LIBFT_SRCS) -L $(LINKS)

all : $(NAME)


clean :
		rm -f $(OBJS) $(LIBFT_OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all	

.PHONY: all clean fclean re
