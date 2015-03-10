/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:52:15 by rmaury            #+#    #+#             */
/*   Updated: 2015/01/27 16:17:27 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

typedef struct		s_point
{
	int				x;
	int				y;

}					t_point;

typedef struct		s_map
{
	int				**map;
	int				col_cnt;
	int				line_cnt;
	int				col;
	int				line;
	int				color;
	int				loc;
	int				zoom;
}					t_map;

typedef struct		s_line
{
	t_point	start;
	t_point	end;
}					t_line;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	t_map			map;
}					t_env;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env e);
void				draw_line(t_env *e, t_point start, t_point end, int color);
void				display_map(t_env *e);
int					gnl_counter(char *file, char *line);
t_map				readmap(char *file, char *line);
int					fdf_error(t_env e, char **env, char **av);

#endif
