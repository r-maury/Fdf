/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 14:55:54 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/27 16:22:04 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_iso(int x, int y, t_env *e)
{
	t_point		start;
	t_point		end;

	start.x = sqrt(2) / 2 * ((y - x) * e->map.zoom) + e->map.loc;
	start.y = (-5 * e->map.map[y][x]) - (1 / sqrt(6) *
		((x + y) * e->map.zoom)) + e->map.loc;
	if (y < e->map.line_cnt - 1)
	{
		end.x = sqrt(2) / 2 * ((y + 1 - x) * e->map.zoom)
			+ e->map.loc;
		end.y = (-5 * e->map.map[y + 1][x]) - (1 / sqrt(6) *
			((x + y + 1) * e->map.zoom)) + e->map.loc;
		draw_line(e, start, end, e->map.color);
	}
	if (x < e->map.col_cnt - 1)
	{
		end.x = sqrt(2) / 2 * ((y - (x + 1)) * e->map.zoom)
			+ e->map.loc;
		end.y = (-5 * e->map.map[y][x + 1]) - (1 / sqrt(6) *
			((x + y + 1) * e->map.zoom)) + e->map.loc;
		draw_line(e, start, end, e->map.color);
	}
}

void			display_map(t_env *e)
{
	int			y;
	int			x;

	e->map.color = 0xFFFFFF;
	e->map.loc = 600;
	e->map.zoom = 50;
	y = 0;
	while (y < e->map.line_cnt)
	{
		x = 0;
		while (x < e->map.col_cnt)
		{
			display_iso(x, y, e);
			x++;
		}
		y++;
	}
}
