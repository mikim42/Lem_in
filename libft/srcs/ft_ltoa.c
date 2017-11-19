/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 23:12:52 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 15:08:38 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ltoa(long n)
{
	char	*s;
	long	nb;
	int		len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -n : n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n > 9)
	{
		s[--len] = (n % 10) + 48;
		n /= 10;
	}
	s[--len] = n + 48;
	return (s);
}
