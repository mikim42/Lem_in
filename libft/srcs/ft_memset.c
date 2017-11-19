/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:09:55 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:29:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)b;
	while ((int)--len >= 0)
		tmp[len] = (unsigned char)c;
	return (b);
}
