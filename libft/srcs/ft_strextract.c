/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:51:35 by mikim             #+#    #+#             */
/*   Updated: 2017/10/15 20:56:33 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strextract(char const *s, int c)
{
	char	*res;
	int		i;

	i = -1;
	while (s[++i] != c)
		;
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while (--i >= 0)
		res[i] = s[i];
	return (res);
}
