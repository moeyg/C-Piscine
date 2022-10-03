/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:21:02 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/11 17:37:00 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	length;

	index = 0;
	length = 0;
	while (src[length] != '\0')
		length ++;
	if (size != 0)
	{
		while (src[index] != '\0' && size - 1 > index)
		{
			dest[index] = src[index];
			index ++;
		}
		dest[index] = '\0';
	}
	return (length);
}
