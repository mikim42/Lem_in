/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:30 by mikim             #+#    #+#             */
/*   Updated: 2017/11/16 16:42:59 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	print_comment(t_env *e)
{
	t_cmt *tmp;

	tmp = e->cmt;
	ft_printf("\n-----{SET:BO}Comment{OFF}-----\n");
	while (tmp)
	{
		ft_printf("{SET:BO}%s{OFF}\n", tmp->comment);
		tmp = tmp->next;
	}
}

void	print_path(t_env *e)
{
	t_path	*tmp;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	ft_printf("\n-----{SET:BO}Path{OFF}-----\n");
	while (++i < e->cnt + 1)
	{
		tmp = e->path[i];
		while (tmp)
		{
			ft_printf("{SET:BO}{CYN}%s{OFF} {SET:BO}- ",
			search_room_num(e->room, i)->name);
			ft_printf("{MGT}%s {RED}DIST:%.2f{OFF}\n",
			search_room_num(e->room, tmp->u)->name, tmp->dist);
			tmp = tmp->next;
			cnt++;
		}
	}
	ft_printf("{SET:BO}Total: {MGT}%d{OFF}\n", cnt);
}

void	print_room(t_env *e)
{
	t_room	*tmp;
	int		cnt;

	tmp = e->room;
	ft_printf("\n-----{SET:BO}Room{OFF}-----\n");
	cnt = 0;
	while (tmp)
	{
		ft_printf("{SET:BO}{BLU}%s {GRN}X:%d {YEL}Y:%d{OFF}\n",
		tmp->name, tmp->x, tmp->y);
		tmp = tmp->next;
		cnt++;
	}
	ft_printf("{SET:BO}Total: {MGT}%d{OFF}\n", cnt);
}

void	print_res_path(t_env *e)
{
	int i;

	i = -1;
	ft_printf("\n-----{SET:BO}Result path{OFF}-----\n");
	ft_printf("{RED}%d: {SET:BO}%s ", i + 1, e->start);
	ft_printf("{OFF}{SET:BO}##START{OFF}\n");
	while (++i < e->size)
	{
		if (i != e->size - 1)
			ft_printf("{RED}%d: {SET:BO}%s{OFF}\n", i + 1, e->res_path[i].name);
		else
		{
			ft_printf("{RED}%d: {SET:BO}%s ", i + 1, e->res_path[i].name);
			ft_printf("{OFF}{SET:BO}##END{OFF}\n");
		}
	}
	ft_printf("{SET:BO}ANT: {MGT}%d{OFF}\n", e->ant);
}

void	print_main(void)
{
	ft_printf("\n");
	ft_printf("[{RED}0{OFF}] Exit\n");
	ft_printf("[{RED}1{OFF}] Check result path\n");
	ft_printf("[{RED}2{OFF}] Check room\n");
	ft_printf("[{RED}3{OFF}] Check path\n");
	ft_printf("[{RED}4{OFF}] Check comment\n");
	ft_printf("[{RED}5{OFF}] Lem_in again\n");
}
