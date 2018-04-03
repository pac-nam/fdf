/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:46:17 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/03 21:11:33 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		ft_write_map(t_point *p1, t_point *p2, t_stock *s)
{
	int	y_map;
	int	x_map;

	y_map = 0;
	while (++y_map <= s->map[0][0])
	{
		x_map = 0;
		while (++x_map <= s->map[y_map][0])
		{
			p1->x = s->ref->x + (x_map - 1) * s->dif_right;
			p1->y = s->ref->y - (x_map - 1) * s->dif_right -
				s->map[y_map][x_map] * s->zoom;
			if (x_map < s->map[y_map][0])
			{
				p2->x = s->ref->x + (x_map) * s->dif_right;
				p2->y = s->ref->y - (x_map) * s->dif_right -
					s->map[y_map][x_map + 1] * s->zoom;
				ft_put_line(p1, p2, s);
			}
			if (y_map < s->map[0][0] && x_map <= s->map[y_map + 1][0])
			{
				p2->x = p1->x + s->dif_up;
				p2->y = s->ref->y - (x_map - 1) * s->dif_right + s->dif_up -
					s->map[y_map + 1][x_map] * s->zoom;
				ft_put_line(p1, p2, s);
			}
		}
		s->ref->x += s->dif_up;
		s->ref->y += s->dif_up;
	}
	return (1);
}

int		ft_fdf(t_stock *s)
{
	t_point		*p1;
	t_point		*p2;

	if (!(p1 = (t_point*)malloc(sizeof(t_point))) ||
			!(p2 = (t_point*)malloc(sizeof(t_point))))
		return (0);
	ft_write_map(p1, p2, s);
	return (1);
}
