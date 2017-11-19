/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:24:54 by mikim             #+#    #+#             */
/*   Updated: 2017/11/18 15:25:41 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

# define DIST_MAX LONG_MAX

typedef struct		s_room
{
	int				n;
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	int				v;
	int				u;
	double			dist;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	int				u;
	double			dist;
	struct s_path	*next;
}					t_path;

typedef struct		s_cmt
{
	char			*comment;
	struct s_cmt	*next;
}					t_cmt;

typedef struct		s_res
{
	int				ant;
	int				n;
	char			*name;
}					t_res;

typedef struct		s_env
{
	t_room			*room;
	t_path			*queue;
	t_link			*link;
	t_path			**path;
	t_res			*res_path;
	t_cmt			*cmt;
	int				ant;
	int				cnt;
	char			*start;
	char			*end;
	double			*dist;
	int				*res;
	int				size;
}					t_env;

/*
**					lem_in
*/
void				lem_in(t_env *e);
void				read_file(t_env *e);
void				get_ants(t_env *e);

/*
**					dijkstra
*/
void				dijkstra(t_env *e);
void				parse_dijkstra(t_env *e);

/*
**					store_handler
*/
void				store_room(t_env *e, char **split);
void				store_link(t_env *e, char **split);
void				store_start(t_env *e);
void				store_end(t_env *e);
void				store_comment(t_cmt **head, char *line);

/*
**					room_handler
*/
t_room				*create_room(t_env *e, char **split);
t_room				*duplicate_room(t_room *room);
void				add_room(t_room **head, t_room *room);
t_room				*search_room(t_room *head, char *link);

/*
**					link_handler
*/
void				add_link(t_link **head, t_link *link);
double				dist_link(t_room *v, t_room *u);
double				babylonian(double input, double guess);

/*
**					path_handler
*/
void				parse_path(t_env *e);
void				add_path(t_path **head, t_path *path);
t_path				*create_path(t_link *link);

/*
**					queue_handler
*/
void				queue_push(t_path **head, int n, double d);
void				queue_pop(t_path **head);

/*
**					move_handler
*/
void				move_ants(t_env *e);
void				parse_move(t_env *e);
t_room				*search_room_num(t_room *head, int n);
void				print_lem_in(t_env *e, int size);
int					res_empty(t_env *e);

/*
**					console_handler
*/
void				console_mod(t_env *e);
void				check_input(t_env *e, char *line);

/*
**					print_handler
*/
void				print_main(void);
void				print_res_path(t_env *e);
void				print_room(t_env *e);
void				print_path(t_env *e);
void				print_comment(t_env *e);

/*
**					error_handler
*/
void				ft_exit(t_env *e, char *msg);
void				destroy_cmt(t_cmt *cmt);
void				destroy_path(t_env *e);
void				destroy_link(t_link *link);
void				destroy_room(t_room *room);

#endif
