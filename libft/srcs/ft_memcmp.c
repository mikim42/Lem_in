/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:01:09 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:28:51 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (n == 0)
		return (0);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (i < n - 1 && c1[i] == c2[i])
		++i;
	return (c1[i] - c2[i]);
}
