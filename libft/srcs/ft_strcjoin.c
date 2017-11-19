/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 01:52:13 by mikim             #+#    #+#             */
/*   Updated: 2017/10/15 01:52:15 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcjoin(char const *s1, char c, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	r = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (r == NULL)
		return (NULL);
	while (s1[j] != '\0')
		r[i++] = s1[j++];
	r[i++] = c;
	j = 0;
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	return (r);
}
