/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 16:52:01 by mikim             #+#    #+#             */
/*   Updated: 2017/11/21 14:11:46 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	store_comment(t_cmt **head, char *line)
{
	t_cmt *new_cmt;
	t_cmt *tmp;

	new_cmt = ft_memalloc(sizeof(t_cmt));
	new_cmt->comment = ft_strdup(line);
	tmp = *head;
	if (!tmp)
	{
		*head = new_cmt;
		return ;
	}
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = new_cmt;
			return ;
		}
		tmp = tmp->next;
	}
}

void	store_end(t_env *e)
{
	char **split;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			store_comment(&e->cmt, line);
			free(line);
		}
		else
			break ;
	}
	split = ft_strsplit(line, ' ');
	free(line);
	e->end = ft_strdup(split[0]);
	store_room(e, split);
}

void	store_start(t_env *e)
{
	char **split;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			store_comment(&e->cmt, line);
			free(line);
		}
		else
			break ;
	}
	split = ft_strsplit(line, ' ');
	free(line);
	e->start = ft_strdup(split[0]);
	store_room(e, split);
}

void	store_link(t_env *e, char **split)
{
	t_link *new_link[2];
	t_room *v[2];
	double dist;

	v[0] = search_room(e->room, split[0]);
	v[1] = search_room(e->room, split[1]);
	if (split[2] || !v[0] || !v[1])
	{
		ft_splitdel(split);
		ft_exit(e, "ERROR");
	}
	new_link[0] = ft_memalloc(sizeof(t_link));
	new_link[1] = ft_memalloc(sizeof(t_link));
	dist = dist_link(v[0], v[1]);
	new_link[0]->v = v[0]->n;
	new_link[0]->u = v[1]->n;
	new_link[0]->dist = dist;
	add_link(&e->link, new_link[0]);
	new_link[1]->v = v[1]->n;
	new_link[1]->u = v[0]->n;
	new_link[1]->dist = dist;
	add_link(&e->link, new_link[1]);
	ft_splitdel(split);
}

void	store_room(t_env *e, char **split)
{
	if (!split[1] || !split[2] || split[3] || split[0][0] == 'L' || e->link ||
		(ft_strlen(split[1]) > 18 || ft_strchr(split[0], '-')) ||
		(ft_strlen(split[2]) > 18))
	{
		ft_splitdel(split);
		ft_exit(e, "ERROR");
	}
	add_room(&e->room, create_room(e, split));
}
