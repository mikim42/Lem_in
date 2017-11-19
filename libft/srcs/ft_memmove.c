/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:03:36 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:28:58 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = -1;
	if (s1 < s2)
		while (++i < len)
			s1[i] = s2[i];
	else
		while ((int)(--len) >= 0)
			s1[len] = s2[len];
	return (dst);
}
