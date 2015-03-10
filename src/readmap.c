/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:46:22 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/26 18:37:36 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	convert(t_map map, int i, char **tab)
{
	if (!(map.map[map.line] = (int*)malloc(sizeof(int) * i)))
		exit (0);
	i = 0;
	while (map.col >= 0)
	{
		map.map[map.line][map.col] = ft_atoi(tab[i]);
		i++;
		map.col--;
	}
	map.line--;
	return (map);
}

t_map			readmap(char *file, char *line)
{
	char	**tab;
	int		fd;
	int		i;
	t_map	map;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit (0);
	map.line_cnt = gnl_counter(file, line);
	if (!(map.map = (int**)malloc(sizeof(int*) * map.line_cnt)))
		exit (0);
	map.line = map.line_cnt - 1;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
			i++;
		map.col_cnt = i;
		map.col = i - 1;
		map = convert(map, i, tab);
	}
	close(fd);
	return (map);
}
