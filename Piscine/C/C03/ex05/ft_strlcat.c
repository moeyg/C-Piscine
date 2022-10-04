/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:28:52 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/06 01:25:13 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;
	unsigned int	src_length;

	index = 0;
	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
		dest_length ++;
	while (src[src_length] != '\0')
		src_length ++;
	if (size > dest_length)
	{
		while (index < size - dest_length - 1 && src[index] != '\0')
		{	
			dest[dest_length + index] = src[index];
			index ++;
		}
		dest[dest_length + index] = '\0';
		return (dest_length + src_length);
	}
	else
		return (size + src_length);
}
