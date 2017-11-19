/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 04:03:47 by mikim             #+#    #+#             */
/*   Updated: 2017/10/15 00:48:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	spec_base(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	init_int_arg(e, &tmp);
	if (type == 'O' || e->mod == pf_hh || e->mod == pf_z || e->mod == pf_t ||
		e->mod == pf_j || e->mod == pf_l || e->mod == pf_ll)
		val = (unsigned long)tmp;
	else if (e->mod == pf_h)
		val = (unsigned short)tmp;
	else if (e->mod == pf_nomod)
		val = (unsigned int)tmp;
	(type == 'b' || type == 'B') ? e->out = ft_ultoa_base(val, 2) : 0;
	(type == 'o' || type == 'O') ? e->out = ft_ultoa_base(val, 8) : 0;
	(type == 'x' || type == 'X') ? e->out = ft_ultoa_base(val, 16) : 0;
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	print_base(e, type, (long)val);
}

void	spec_precision(t_pf_env *e, char type)
{
	long double	ld;
	double		d;

	if (e->mod == pf_L)
	{
		init_long_double(e, &ld);
		if (ld != ld || (ld * 2 == ld && ld != 0))
			return (nan_inf(e, type, ld));
	}
	else
	{
		init_prec_arg(e, &d);
		if (d != d || (d * 2 == d && d != 0))
			return (nan_inf(e, type, d));
		ld = (long double)d;
	}
	if (type == 'e' || type == 'E')
		return (print_prec_e(e, ld, type));
	if (type == 'f' || type == 'F')
		return (print_prec_f(e, ld));
	if (type == 'g' || type == 'G')
		return (print_prec_g(e, ld, type));
	if (type == 'a' || type == 'A')
		return (print_prec_a(e, ld, type));
}

void	spec_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (print_null_str(e));
		e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}

void	spec_unsint(t_pf_env *e, char type)
{
	long tmp;

	e->flag.sp = 0;
	e->flag.plus = 0;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U' || e->mod == pf_z || e->mod == pf_l ||
			e->mod == pf_t || e->mod == pf_j || e->mod == pf_ll)
		e->out = ft_ultoa((unsigned long)tmp);
	else if (e->mod == pf_h)
		e->out = ft_ultoa((unsigned short)tmp);
	else if (e->mod == pf_hh)
		e->out = ft_ultoa((unsigned char)tmp);
	else if (e->mod == pf_nomod && type != 'U')
		e->out = ft_ultoa((unsigned int)tmp);
	print_digit(e);
}

void	spec_int(t_pf_env *e)
{
	long tmp;
	long i;

	init_int_arg(e, &tmp);
	i = (long long)tmp;
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	e->flag.prec >= 0 ? e->flag.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->mod == pf_hh)
		e->out = ft_itoa((char)i);
	else if (e->mod == pf_h)
		e->out = ft_itoa((short)i);
	else if (e->mod == pf_nomod)
		e->out = ft_itoa((int)i);
	else if (e->mod == pf_l || e->mod == pf_t ||
			e->mod == pf_ll || e->mod == pf_j)
		e->out = ft_ltoa((long)i);
	print_digit(e);
}
