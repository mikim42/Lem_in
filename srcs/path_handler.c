/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:58:59 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 15:24:35 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_path	*create_path(t_link *link)
{
	t_path *new_path;

	new_path = ft_memalloc(sizeof(t_path));
	new_path->u = link->u;
	new_path->dist = link->dist;
	return (new_path);
}

void	add_path(t_path **head, t_path *path)
{
	t_path *tmp;

	tmp = *head;
	if (!tmp)
		*head = path;
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = path;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	parse_path(t_env *e)
{
	t_path *path;
	t_link *link;

	e->path = ft_memalloc(sizeof(t_path*) * (e->cnt + 2));
	link = e->link;
	while (link)
	{
		path = create_path(link);
		add_path(&e->path[link->v], path);
		link = link->next;
	}
}
