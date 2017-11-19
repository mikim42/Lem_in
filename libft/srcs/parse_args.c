/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 03:25:42 by mikim             #+#    #+#             */
/*   Updated: 2017/10/15 01:30:59 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	get_mod(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == 'h' && fmt[e->i + 1] != 'h' && e->mod == pf_nomod)
		e->mod = pf_h;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] == 'h' && e->mod == pf_nomod)
	{
		e->mod = pf_hh;
		++e->i;
	}
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] != 'l')
		e->mod = pf_l;
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] == 'l')
	{
		e->mod = pf_ll;
		++e->i;
	}
	else if (fmt[e->i] == 'z')
		e->mod = pf_z;
	else if (fmt[e->i] == 'j')
		e->mod = pf_j;
	else if (fmt[e->i] == 'L')
		e->mod = pf_L;
	else if (fmt[e->i] == 't')
		e->mod = pf_t;
}

void	get_width(t_pf_env *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width = -e->flag.width;
		e->flag.minus = 1;
	}
}

void	get_prec(const char *restrict fmt, t_pf_env *e)
{
	if (e->flag.prec >= 0)
	{
		++e->i;
		return ;
	}
	if (fmt[e->i] == '.' && fmt[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (fmt[e->i] == '.')
	{
		++e->i;
		e->flag.prec = ft_atoi(fmt + e->i);
		while (FT_ISNUM(fmt[e->i]))
			++e->i;
	}
}

void	get_flag(const char *restrict fmt, t_pf_env *e)
{
	while (ft_strchr(PF_FLAG, fmt[e->i]))
	{
		fmt[e->i] >= 'L' && fmt[e->i] <= 'z' ? get_mod(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sp = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '*' ? get_width(e) : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			get_prec(fmt, e);
		else if (fmt[e->i] >= '1' && fmt[e->i] <= '9' && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(fmt + e->i);
			while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
				++e->i;
		}
		else
			++e->i;
	}
}

void	get_tag(const char *restrict fmt, t_pf_env *e)
{
	int	i;
	int tmp;

	init_flag(&e->flag);
	e->mod = pf_nomod;
	e->tag.tag = 0;
	i = 0;
	if (fmt[e->i] >= '0' && fmt[e->i] <= '9')
	{
		tmp = ft_atoi(fmt + e->i);
		while (fmt[e->i + i] >= '0' && fmt[e->i + i] <= '9')
			i++;
		if (fmt[e->i + i] == '$')
		{
			e->tag.tag = 1;
			e->tag.pos = tmp;
			e->i += i + 1;
		}
	}
}
