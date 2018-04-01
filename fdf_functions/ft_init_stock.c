/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 13:52:47 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	ft_init_stock(t_stock *s, char *file)
{
	s->win_width = 500;
	s->win_height = 500;
	s->color = 0x00FFFF;
	s->mlx = mlx_init();
        s->win = mlx_new_window(s->mlx, s->win_width, s->win_height, "FDF");
	if (!(ft_init_map(file, &s->map)))
		return (0);
	s->zoom = 1;
	return (1);
}
