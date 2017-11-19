/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:48:16 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:30:45 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_strlen_nospaces(char *s, int *start, int *end)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
			s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		++i;
	*start = i;
	while (s[++j])
		;
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t' ||
			s[j - 1] == '\v' || s[j - 1] == '\f' || s[j - 1] == '\r')
		--j;
	*end = j;
}

char		*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	ft_strlen_nospaces((char*)s, &i, &j);
	if (i >= j)
	{
		r = (char*)malloc(1);
		r[0] = '\0';
		return (r);
	}
	if (!(r = (char*)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	k = -1;
	while (i <= j)
		r[++k] = s[i++];
	r[k] = '\0';
	return (r);
}
