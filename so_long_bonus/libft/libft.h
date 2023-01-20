/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:20:51 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 18:27:31 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_count_char(char *s, char c);
int		ft_strncmp(char *str1, char *str2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t n, size_t s);
void	ft_bzero(void *str, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(void *dest, const void *src, size_t n);

//Get Next line functions
# define BUFFER_SIZE 1024

void	get_line(char **buf, char **line);
char	*ft_last_line(char **buff);
char	*get_next_line(int fd);
char	*ft_line(int fd, char **buff, char *temp, char *line);

#	endif