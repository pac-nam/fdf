/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:08:51 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 18:07:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

#include <stdio.h>
//		ROUGE
static int		ft_put_line_nne_ssw(t_point *p1, t_point *p2, t_stock *s)
{
	float   e;
	float   to_add;
	int	x;
	int	y;

	e = 0;
	to_add = 1 / -((float)(p2->y - p1->y) / (float)(p2->x - p1->x));
	x = p1->x;
	y = p1->y;
	while (x <= p2->x)
	{
		while (e <= 0.5 && y >= p2->y)
		{
			mlx_pixel_put(s->mlx, s->win, x, y--, 0xFF0000);
			e += to_add;
		}
		e -= 1;
		++x;
	}
	return (1);
}

//		BLEU
static int		ft_put_line_nnw_sse(t_point *p1, t_point *p2, t_stock *s)
{
	float	e;
	float	to_add;
	int	x;
	int	y;

	e = 0;
	to_add = 1 / ((float)(p2->y - p1->y) / (float)(p2->x - p1->x));
	x = p1->x;
	y = p1->y;
	while (x <= p2->x)
	{
		while (e <= 0.5 && y <= p2->y)
		{
			mlx_pixel_put(s->mlx, s->win, x, y++, 0x0000FF);
			e += to_add;
		}
		e -= 1;
		++x;
	}
	return (1);
}

//              VERT
static int              ft_put_line_ene_wsw(t_point *p1, t_point *p2, t_stock *s)
{
	float   e;
	float   to_add;
	int	x;
	int	y;

	e = 0;
	to_add = -((float)(p2->y - p1->y) / (float)(p2->x - p1->x));
	x = p1->x;
	y = p1->y;
	while (y >= p2->y)
	{
		while (e <= 0.5 && x <= p2->x)
		{
			mlx_pixel_put(s->mlx, s->win, x++, y, 0x00FF00);
			e += to_add;
		}
		e -= 1;
		--y;
	}
	return (1);
}

//              JAUNE
static int              ft_put_line_ese_wnw(t_point *p1, t_point *p2, t_stock *s)
{
	float   e;
	float   to_add;
	int	x;
	int	y;

	e = 0;
	to_add = ((float)(p2->y - p1->y) / (float)(p2->x - p1->x));
	x = p1->x;
	y = p1->y;
	while (y <= p2->y)
	{
		while (e <= 0.5 && x <= p2->x)
		{
			mlx_pixel_put(s->mlx, s->win, x++, y, 0xFFFF00);
			e += to_add;
		}
		e -= 1;
		++y;
	}
	return (1);
}

int				ft_put_line(t_point *p1, t_point *p2, t_stock *s)
{
	t_point	*tmp;

	if (p1->x > p2->x)
	{
		tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	if (((float)(p2->y - p1->y) / (float)(p2->x - p1->x)) > 1 ||
			((float)(p2->y - p1->y) / (float)(p2->x - p1->x)) < -1)
	{
		if (p1->y < p2->y)
			return (ft_put_line_nnw_sse(p1, p2, s));
		return (ft_put_line_nne_ssw(p1, p2, s));
	}
	if (p1->y < p2->y)
		return (ft_put_line_ese_wnw(p1, p2, s));
	return (ft_put_line_ene_wsw(p1, p2, s));
}
