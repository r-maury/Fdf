/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:39:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/27 16:40:24 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		gnl_counter(char *file, char *line)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
		i++;
	close(fd);
	return (i);
}
