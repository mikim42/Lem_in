/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 16:05:14 by mikim             #+#    #+#             */
/*   Updated: 2017/11/07 16:16:05 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	get_ants(t_env *e)
{
	char *line;

	line = NULL;
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
	if (line == NULL)
		ft_exit(e, "ERROR");
	e->ant = ft_atoi(line);
	free(line);
	if (e->ant <= 0)
		ft_exit(e, "ERROR");
}

void	read_file(t_env *e)
{
	char *line;

	get_ants(e);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "##start"))
			store_start(e);
		else if (!ft_strcmp(line, "##end"))
			store_end(e);
		else if (line[0] == '#')
			store_comment(&e->cmt, line);
		else if (ft_strchr(line, ' '))
			store_room(e, ft_strsplit(line, ' '));
		else if (ft_strchr(line, '-'))
			store_link(e, ft_strsplit(line, '-'));
		else
		{
			free(line);
			ft_exit(e, "ERROR");
		}
		free(line);
	}
}

void	lem_in(t_env *e)
{
	read_file(e);
	if (!e->start || !e->end)
		ft_exit(e, "ERROR");
	parse_path(e);
	dijkstra(e);
	move_ants(e);
	console_mod(e);
	ft_exit(e, NULL);
}
