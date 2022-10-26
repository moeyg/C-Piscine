/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:56 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 11:36:10 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	standard_input(char *buffer, int buffer_size)
{
	int	index;

	index = 0;
	while (read(0, buffer, buffer_size - index) > 0)
	{
		index = 0;
		while (buffer[index] != '\0' && buffer[index] != '\n')
		{
			index ++;
		}
		*(buffer + index++) = '\n';
		buffer += index;
	}
}
