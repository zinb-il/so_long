/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:42:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/05 22:19:51 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_line(char **buf, char **line)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (*(buf))
	{
		buff = *(buf);
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				*(line) = ft_substr(buff, 0, i);
				if (ft_strlen(*(buf)) > (i + 1))
					*(buf) = ft_substr(buff, i + 1, ft_strlen(*(buf)) - i);
				else
					*(buf) = NULL;
				free (buff);
				break ;
			}
			i++;
		}
	}
}

char	*ft_last_line(char **buff)
{
	char	*line;
	int		l;

	line = NULL;
	l = 0;
	get_line(buff, &line);
	if (!line)
		line = *(buff);
	*(buff) = NULL;
	return (line);
}

char	*ft_line(int fd, char **buff, char *temp, char *line)
{
	int		r;

	while (!line)
	{
		r = read(fd, temp, BUFFER_SIZE);
		if (r <= 0)
			break ;
		temp[r] = '\0';
		if (!*(buff))
			*(buff) = ft_strdup(temp);
		else
			*(buff) = ft_strjoin(*(buff), temp);
		get_line(buff, &line);
	}
	if (!line && r <= 0 && *(buff))
		line = ft_last_line(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	if (buff)
		get_line(&buff, &line);
	if (!line)
		line = ft_line(fd, &buff, temp, line);
	free(temp);
	return (line);
}
