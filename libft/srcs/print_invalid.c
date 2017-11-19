/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:47:27 by mikim             #+#    #+#             */
/*   Updated: 2017/10/14 22:00:39 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_invalid_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	print_invalid_spec(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c, 1);
		print_invalid_width(e);
	}
	else
	{
		print_invalid_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
