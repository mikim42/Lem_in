/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:44:59 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:30:42 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	res = (char*)big;
	if (!little[0])
		return (res);
	while (res[++i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j + 1])
				return (&res[i]);
			++j;
		}
	}
	return (NULL);
}
