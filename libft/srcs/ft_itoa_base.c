/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:55:03 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 23:42:16 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base(int n, int base)
{
	char	*s;
	long	nb;
	int		len;

	len = 1;
	nb = n < 0 ? -(long)n : n;
	nb < 0 ? ++len : 0;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long)n : n;
	while (nb >= base)
	{
		s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
		nb /= base;
	}
	s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
	return (s);
}
