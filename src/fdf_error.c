/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:36:30 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/27 16:40:01 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_error(t_env e, char **env, char **av)
{
	if (!env[0])
	{
		ft_putendl("Error: Environement Not Found");
		return (1);
	}
	if (!av[1])
	{
		ft_putendl("Error: None Map Added");
		return (1);
	}
	if (!e.map.map)
	{
		ft_putendl("Error: Invalid Map Added");
		return (1);
	}
	return (0);
}
