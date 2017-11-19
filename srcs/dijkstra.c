/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:18:39 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 15:25:13 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	parse_dijkstra(t_env *e)
{
	t_room	*tmp;
	int		i;

	e->dist = (double*)malloc(sizeof(double) * (e->cnt + 1));
	i = -1;
	while (++i < e->cnt + 1)
		e->dist[i] = DIST_MAX;
	e->res = (int*)malloc(sizeof(int) * (e->cnt + 1));
	i = -1;
	while (++i < e->cnt + 1)
		e->res[i] = -1;
	tmp = search_room(e->room, e->start);
	e->res[tmp->n] = 0;
	e->dist[tmp->n] = 0;
	queue_push(&e->queue, tmp->n, 0);
}

void	dijkstra(t_env *e)
{
	t_path	*ptmp;
	int		itmp;
	double	dtmp;

	parse_dijkstra(e);
	while (e->queue)
	{
		itmp = e->queue->u;
		dtmp = e->queue->dist;
		ptmp = e->path[itmp];
		queue_pop(&e->queue);
		if (dtmp <= e->dist[itmp])
		{
			while (ptmp)
			{
				if (e->dist[ptmp->u] > e->dist[itmp] + ptmp->dist)
				{
					e->dist[ptmp->u] = e->dist[itmp] + ptmp->dist;
					queue_push(&e->queue, ptmp->u, e->dist[ptmp->u]);
					e->res[ptmp->u] = itmp;
				}
				ptmp = ptmp->next;
			}
		}
	}
}
