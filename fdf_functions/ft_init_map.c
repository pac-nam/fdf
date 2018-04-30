/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:35:54 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/30 11:03:03 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../header/fdf.h"

static int	ft_number_of_number(char *str)
{
	int		i;
	int		quantity;

	i = 0;
	quantity = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			++i;
		if (!str[i])
			return (quantity);
		if (str[i] == '-' || str[i] == '+')
			++i;
		if (!ft_isdigit(str[i]))
			return (-1);
		while (ft_isdigit(str[i]))
			++i;
		++quantity;
	}
	return (quantity);
}

static int	ft_nb_line(char *file)
{
	int		fd;
	int		ret;
	int		count;
	char	buf[GNL_BUFF_SIZE + 1];

	count = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		while (--ret >= 0)
			if (buf[ret] == '\n')
				++count;
	}
	if (ret == -1)
		return (-1);
	close(fd);
	return (count);
}

static int	ft_map_line(int **map, char *line)
{
	int		length;
	int		i;
	int		index;

	i = 0;
	if ((length = ft_number_of_number(line)) == -1)
		return (0);
	if (!(*map = (int*)malloc(sizeof(int) * (length + 1))))
		return (0);
	(*map)[0] = length;
	index = 1;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			++i;
		if (line[i] == '-' || line[i] == '+' || ft_isdigit(line[i]))
			(*map)[index++] = ft_atoi(&(line[i++]));
		else
			return (0);
		while (ft_isdigit(line[i]))
			++i;
	}
	return (1);
}

static int	ft_end_init_map(int ret, int fd)
{
	if (ret == -1)
		return (0);
	close(fd);
	return (1);
}

int			ft_init_map(char *file, int ***map)
{
	int		fd;
	int		ret;
	int		index;
	int		column;
	char	*line;

	index = 1;
	column = ft_nb_line(file);
	if (!(*map = (int**)malloc(sizeof(int*) * (column + 1))) ||
			!(**map = (int*)malloc(sizeof(int))))
		return (0);
	(*map)[0][0] = column;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while ((ret = ft_gnl(fd, &line)) > 0)
	{
		if (!(ft_map_line(&((*map)[index++]), line)))
		{
			ft_putstr("wrong character in file\n");
			return (0);
		}
		ft_strdel(&line);
	}
	return (ft_end_init_map(ret, fd));
}
