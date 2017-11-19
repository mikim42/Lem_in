/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:58:01 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:28:46 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	if (!(s = malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		s[i] = '\0';
	return ((void*)s);
}
