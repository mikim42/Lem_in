/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:44:14 by mikim             #+#    #+#             */
/*   Updated: 2017/11/07 15:59:30 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	check_input(t_env *e, char *line)
{
	if (line[0] == '0')
	{
		free(line);
		ft_exit(e, NULL);
	}
	else if (line[0] == '1')
		print_res_path(e);
	else if (line[0] == '2')
		print_room(e);
	else if (line[0] == '3')
		print_path(e);
	else if (line[0] == '4')
		print_comment(e);
	else if (line[0] == '5')
	{
		ft_printf("\n");
		move_ants(e);
	}
	else
		ft_printf("Try again.\n");
	free(line);
	return (console_mod(e));
}

void	console_mod(t_env *e)
{
	char *line;

	print_main();
	line = NULL;
	get_next_line(1, &line);
	if (!line || line[1] != '\0')
	{
		ft_printf("Try again.\n");
		if (line)
			free(line);
		return (console_mod(e));
	}
	check_input(e, line);
}
