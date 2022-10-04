/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:02:55 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/05 22:30:05 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	length;

	index = 0;
	length = 0;
	while (dest[length] != '\0')
	{
		length ++;
	}
	while (index < nb && src[index] != '\0')
	{
		dest[length + index] = src[index];
		index ++;
	}
	dest[length + index] = '\0';
	return (dest);
}
