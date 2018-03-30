/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 13:52:47 by tbleuse          ###   ########.fr       */
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
	exit (0);
}

int		deal_key(int key, void *stock)
{
	ft_printf("%d\n", key);
	if (key == 53)
		ft_end_fdf(stock);
	return (0);
}

int		main(int ac, char **av)
{
	t_stock	*s;

	if (ac < 2)
	{
		write(2, "missing map\n", 12);
		return (0);
	}
	if (!(s = (t_stock*)malloc(sizeof(t_stock))) ||
			!(ft_init_map(av[1], &s->map)))
		return (0);
	ft_print_int_tab(s->map);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx_key_hook(s->win, deal_key, s);
	if (!(ft_fdf(s)))
	{
		write(2, "Interruption involontaire du programme\n", 39);
		return (0);
	}
	mlx_loop(s->mlx);
}
