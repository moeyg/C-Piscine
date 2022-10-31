/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:36:15 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 12:00:40 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(int fd)
{
	t_map		*map_info;
	t_square	*square;

	map_info = 0;
	if (fd > 0)
		map_info = read_map(fd);
	else if (fd == 0)
		map_info = read_map(0);
	if (!map_info)
	{
		ft_putstr(MAP_ERR);
		return ;
	}
	square = find_square(map_info);
	print_answer(map_info, square);
	free_map(map_info, map_info->height);
	free(square);
}

int	main(int argc, char *argv[])
{
	int		index;
	int		fd;

	if (argc == 1)
		bsq(0);
	else
	{
		index = 1;
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			if (fd == -1)
				ft_putstr(MAP_ERR);
			else
				bsq(fd);
			if (argc > 2 && index < argc - 1)
				ft_putchar('\n');
			index++;
		}
	}
	return (0);
}
