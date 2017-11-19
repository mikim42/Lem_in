/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 21:05:12 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 15:24:17 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

double	babylonian(double input, double guess)
{
	double prev;
	double res;

	prev = guess;
	res = input / prev;
	guess = (prev + res) / 2;
	if (guess > prev * 1.01 || guess < prev * 0.99)
		return (babylonian(input, guess));
	return (guess);
}

double	dist_link(t_room *v, t_room *u)
{
	double	hypo;
	long	a;
	long	b;

	a = (long)v->x - u->x;
	b = (long)v->y - u->y;
	hypo = (double)((a * a) + (b * b));
	hypo = babylonian(hypo, hypo / 2);
	return (hypo);
}

void	add_link(t_link **head, t_link *link)
{
	t_link *tmp;

	tmp = *head;
	if (!tmp)
		*head = link;
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = link;
				return ;
			}
			tmp = tmp->next;
		}
	}
}
