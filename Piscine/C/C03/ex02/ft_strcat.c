/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:53:20 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/05 19:07:21 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	index;
	unsigned int	length;

	index = 0;
	length = 0;
	while (dest[length] != '\0')
	{
		length ++;
	}
	while (src[index] != '\0')
	{
		dest[length + index] = src[index];
		index ++;
	}
	dest[length + index] = '\0';
	return (dest);
}	
