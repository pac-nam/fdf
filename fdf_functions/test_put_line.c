/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:46:17 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/23 15:04:15 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		test_put_line_second(t_point *p1, t_point *p2, int change, t_stock *s)
{
	while (p2->y <= p1->y)
	{
		ft_put_line(p1, p2, s);
		p2->x += change;
		p2->y += change;
	}
	while (p2->y <= s->win_height)
	{
		ft_put_line(p1, p2, s);
		p2->x -= change;
		p2->y += change;
	}
	while (p2->y >= p1->y)
	{
		ft_put_line(p1, p2, s);
		p2->x -= change;
		p2->y -= change;
	}
	while (p2->y >= 0)
	{
		ft_put_line(p1, p2, s);
		p2->x += change;
		p2->y -= change;
	}
	ft_put_line(p1, p2, s);
	return (1);
}

int		test_put_line(t_stock *s)
{
	t_point		*p1;
	t_point		*p2;
	int		change = 1;

	if (!(p1 = (t_point*)malloc(sizeof(t_point))) ||
			!(p2 = (t_point*)malloc(sizeof(t_point))))
		return (0);
	p1->x = s->win_width / 2;
	p2->x = s->win_width / 2;
	p1->y = s->win_height / 2;
	p2->y = 0;
	return (test_put_line_second(p1, p2, change, s);
}
