/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:41:02 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 12:19:43 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_first_line(int fd)
{
	char	*line;
	char	c;
	int		index;

	index = 0;
	line = (char *)safe_malloc(100000);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			line[index] = '\0';
			break ;
		}
		line[index++] = c;
	}
	if (index == 0)
	{
		free(line);
		return (0);
	}
	return (line);
}

int	read_map_info(t_map *map_info, char *first_line)
{
	int	len;

	len = ft_strlen(first_line);
	if (len < 4)
	{
		free_map_info(map_info, first_line);
		return (0);
	}
	map_info->empty = first_line[len - 3];
	map_info->obstacle = first_line[len - 2];
	map_info->full = first_line[len - 1];
	if (!is_map_info_valid(map_info))
		return (free_map_info(map_info, first_line));
	first_line[len - 3] = '\0';
	if (!is_number(first_line[0]))
	{
		free_map_info(map_info, first_line);
		exit(0);
	}
	map_info->height = ft_atoi(first_line);
	if (map_info->height == 0)
		return (free_map_info(map_info, first_line));
	return (!free_map_info(0, first_line));
}

int	set_line(t_map *map_info, int row, char *start, char *end)
{
	int		len;
	char	*line;

	if (row > map_info->height)
		return (0);
	len = end - start;
	if (map_info->width == 0)
		map_info->width = len;
	else if (map_info->width != len)
		return (0);
	line = (char *)safe_malloc(len + 1);
	if (!ft_strncpy(line, start, len))
	{
		free(line);
		return (0);
	}
	map_info->arr[row] = line;
	return (1);
}

int	parse_line(t_map *map_info, char *data)
{
	char	*start_add;
	int		row;

	map_info->width = 0;
	row = 0;
	start_add = data;
	while (*data)
	{
		if (*data == '\n')
		{
			if (!set_line(map_info, row, start_add, data))
				break ;
			if (*(data + 1))
				start_add = data + 1;
			row++;
		}
		data++;
	}
	if (row != map_info->height)
	{
		free(map_info->arr[row - 1]);
		free_map(map_info, row - 1);
		return (0);
	}
	return (1);
}

t_map	*read_map(int fd)
{
	t_map	*map_info;
	char	*raw_data;

	map_info = (t_map *)safe_malloc(sizeof(t_map));
	if (!read_map_info(map_info, read_first_line(fd)))
		return (0);
	map_info->arr = (char **)safe_malloc(sizeof(char *) * map_info->height);
	raw_data = (char *)safe_malloc(MAX_BUF_SIZE + 1);
	if (fd == 0)
		standard_input(raw_data, MAX_BUF_SIZE);
	else
	{
		if (!read(fd, raw_data, MAX_BUF_SIZE))
		{
			free_data(map_info, raw_data);
			return (0);
		}
	}
	if (!parse_line(map_info, raw_data))
	{
		free(raw_data);
		return (0);
	}
	free(raw_data);
	return (map_info);
}
