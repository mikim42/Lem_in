/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:37:01 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:30:36 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = -1;
	res = (char*)big;
	if (!little[0])
		return (res);
	while (res[++i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&res[i]);
			++j;
		}
	}
	return (NULL);
}
