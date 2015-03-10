/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:04:50 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/27 16:23:06 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av, char **env)
{
	t_env	e;
	char	*line;

	line = NULL;
	e.map = readmap(av[1], line);
	if (fdf_error(e, env, av) == 1)
		return (0);
	(void)ac;
	(void)env;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1020, 1020, "fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
