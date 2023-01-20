/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:25:37 by ziloughm          #+#    #+#             */
/*   Updated: 2021/12/05 18:00:13 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	p = malloc(n * s);
	if (!p)
		return (0);
	ft_bzero(p, n * s);
	return (p);
}
