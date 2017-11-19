/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:58:20 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:28:48 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
