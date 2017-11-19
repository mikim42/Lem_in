/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:04:54 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:30:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (c1[i] && c1[i] == c2[i])
		++i;
	return (c1[i] - c2[i]);
}
