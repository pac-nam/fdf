/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/23 15:09:02 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../header/fdf.h"

static void	ft_end_fdf(t_stock *stock)
{
	while (stock->map[0][0] > 0)
		ft_memdel((void**)&stock->map[stock->map[0][0]--]);
	ft_memdel((void**)&stock->map[0]);
	ft_memdel((void**)&stock->map);
	ft_memdel((void**)&stock);
	ft_putstr("Interruption du programme \"fdf\"\n");
	exit(0);
}

static int	ft_modif_key(int key, t_stock *s)
{
	if (key == 123)
		--s->cam_x;
	else if (key == 124)
		++s->cam_x;
	else if (key == 125)
		++s->cam_y;
	else if (key == 126)
		--s->cam_y;
	else if (key == 89)
		++s->zoom;
	else if (key == 86)
		--s->zoom;
	else if (key == 91)
	{
		s->dif_right_y += 10;
		s->dif_up_y += 10;
	}
	else if (key == 87)
	{
		s->dif_right_y -= 10;
		s->dif_up_y -= 10;
	}
	return (1);
}

static int	ft_modif_stock(int key, t_stock *s)
{
	ft_modif_key(key, s);
	s->ref->x = s->safe + (s->cam_x * s->cam_dif);
	s->ref->y = s->win_height / 2 + (s->cam_y * s->cam_dif);
	ft_all_screen(s, 0);
	if (!(ft_fdf(s)))
	{
		write(2, "Interruption involontaire du programme\n", 39);
		return (0);
	}
	ft_printf("refresh\n", key);
	return (1);
}

int			deal_key(int key, void *s)
{
	ft_printf("%d\n", key);
	if ((123 <= key && key <= 126) || (86 <= key && key <= 92))
		if (!ft_modif_stock(key, s))
			return (0);
	if (key == 53)
		ft_end_fdf(s);
	return (1);
}

int			main(int ac, char **av)
{
	t_stock	*s;

	if (ac < 2)
	{
		write(2, "missing map\n", 12);
		return (0);
	}
	if (!(s = (t_stock*)malloc(sizeof(t_stock))) ||
			!(s->ref = (t_point*)malloc(sizeof(t_point))) ||
			!(ft_init_stock(s, av[1])))
		return (0);
	ft_print_int_tab(s->map);
	if (!mlx_key_hook(s->win, deal_key, s))
		return (0);
	if (!(ft_fdf(s)))
	{
		write(2, "Interruption involontaire du programme\n", 39);
		return (0);
	}
	mlx_loop(s->mlx);
}
