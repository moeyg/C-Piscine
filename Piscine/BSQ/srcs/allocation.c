/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:31:05 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 12:21:11 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*safe_malloc(int size)
{
	void	*buffer;

	buffer = malloc(size);
	if (!buffer)
		exit(0);
	return (buffer);
}

int	free_map_info(t_map *map, char *info)
{
	if (map)
		free(map);
	free(info);
	return (0);
}

void	free_map(t_map *map, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		free(map->arr[index]);
		index ++;
	}
	free(map->arr);
	free(map);
}

void	free_data(t_map *map_info, char *raw_data)
{
	free(map_info);
	free(raw_data);
}
