/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:46:46 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 23:39:07 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		s2[i] = s[start + i];
	s2[i] = '\0';
	return (s2);
}
