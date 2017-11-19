/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:46:36 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 13:30:40 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_fill(char **r, char *s, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			++i;
			++len;
		}
		if (s[i - 1] != c)
			r[++j] = ft_strsub(s, i - len, len);
	}
}

static int	ft_check_wd(char const *s, char c)
{
	int flag;
	int cnt;
	int i;

	i = -1;
	cnt = 0;
	flag = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
	}
	return (cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		wds;

	if (!s)
		return (NULL);
	wds = ft_check_wd(s, c);
	if (!(r = (char**)malloc(sizeof(char*) * (wds + 1))))
		return (NULL);
	r[wds] = NULL;
	ft_fill(r, (char*)s, c);
	return (r);
}
