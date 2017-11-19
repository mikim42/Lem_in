/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:38 by mikim             #+#    #+#             */
/*   Updated: 2017/11/16 16:42:04 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room	*search_room(t_room *head, char *link)
{
	t_room *tmp;

	if (!link)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, link))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	add_room(t_room **head, t_room *room)
{
	t_room *tmp;

	tmp = *head;
	if (!tmp)
		*head = room;
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = room;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

t_room	*duplicate_room(t_room *room)
{
	t_room *new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->n = room->n;
	new_room->name = ft_strdup(room->name);
	new_room->x = room->x;
	new_room->y = room->y;
	return (new_room);
}

t_room	*create_room(t_env *e, char **split)
{
	t_room *new_room;

	new_room = ft_memalloc(sizeof(t_room));
	new_room->n = ++e->cnt;
	new_room->name = ft_strdup(split[0]);
	new_room->x = ft_atoi(split[1]);
	new_room->y = ft_atoi(split[2]);
	ft_splitdel(split);
	return (new_room);
}
