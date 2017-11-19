/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:11:43 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 23:38:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		;
	while (s2[++j])
		;
	if (!(r = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	j = -1;
	while (s2[++j])
		r[i++] = s2[j];
	r[i] = '\0';
	return (r);
}
