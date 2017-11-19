/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:55:19 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 15:24:03 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	destroy_room(t_room *room)
{
	if (room)
	{
		if (room->name)
			free(room->name);
		destroy_room(room->next);
		free(room);
	}
}

void	destroy_link(t_link *link)
{
	if (link)
	{
		destroy_link(link->next);
		free(link);
	}
}

void	destroy_path(t_env *e)
{
	t_path	*tmp;
	t_path	*del;
	int		i;

	i = -1;
	while (++i < e->cnt + 1)
	{
		tmp = e->path[i];
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
	}
	free(e->path);
}

void	destroy_cmt(t_cmt *cmt)
{
	if (cmt)
	{
		if (cmt->comment)
			free(cmt->comment);
		destroy_cmt(cmt->next);
		free(cmt);
	}
}

void	ft_exit(t_env *e, char *msg)
{
	if (e->room)
		destroy_room(e->room);
	if (e->link)
		destroy_link(e->link);
	if (e->path)
		destroy_path(e);
	if (e->res_path)
		free(e->res_path);
	if (e->cmt)
		destroy_cmt(e->cmt);
	if (e->start)
		free(e->start);
	if (e->end)
		free(e->end);
	if (e->dist)
		free(e->dist);
	if (e->res)
		free(e->res);
	if (msg)
		ft_printf("%s\n", msg);
	exit(0);
}
