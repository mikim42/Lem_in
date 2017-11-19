/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_etc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 23:37:20 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 21:34:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	init_wstr_arg(t_pf_env *e, wchar_t **tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], wchar_t *);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t *);
}

void	init_wchar_arg(t_pf_env *e, wchar_t *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], wchar_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t);
}
