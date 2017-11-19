/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:09:03 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 17:05:50 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		res_empty(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->size)
		if (e->res_path[i].ant != 0)
			return (0);
	return (1);
}

void	print_lem_in(t_env *e, int size)
{
	int flag;

	flag = 0;
	while (--size >= 0)
	{
		if (e->res_path[size].ant != 0)
		{
			if (flag++ == 0)
				ft_printf("L%d-%s",
				e->res_path[size].ant, e->res_path[size].name);
			else
				ft_printf(" L%d-%s",
				e->res_path[size].ant, e->res_path[size].name);
		}
	}
	ft_printf("\n");
}

t_room	*search_room_num(t_room *head, int n)
{
	t_room *tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->n == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	parse_move(t_env *e)
{
	t_room	*tmp;
	int		rev;
	int		cnt;

	tmp = search_room(e->room, e->end);
	rev = e->res[tmp->n];
	if (rev == -1)
		ft_exit(e, "ERROR");
	cnt = 0;
	while (rev != 0 && ++cnt > 0)
		rev = e->res[rev];
	e->res_path = ft_memalloc(sizeof(t_res) * (cnt));
	e->size = cnt;
	rev = e->res[tmp->n];
	e->res_path[--cnt].name = tmp->name;
	e->res_path[cnt].n = tmp->n;
	while (e->res[rev] != 0)
	{
		e->res_path[--cnt].name = search_room_num(e->room, rev)->name;
		e->res_path[cnt].n = rev;
		rev = e->res[rev];
	}
}

void	move_ants(t_env *e)
{
	int		ant;
	int		i;

	if (!e->res_path)
		parse_move(e);
	ant = 0;
	while (++ant <= e->ant)
	{
		e->res_path[0].ant = ant;
		print_lem_in(e, e->size);
		i = e->size;
		while (--i)
			e->res_path[i].ant = e->res_path[i - 1].ant;
		e->res_path[0].ant = 0;
	}
	while (!res_empty(e))
	{
		print_lem_in(e, e->size);
		i = e->size;
		while (--i)
			e->res_path[i].ant = e->res_path[i - 1].ant;
	}
}
