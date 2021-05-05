/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:23:28 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/24 10:42:01 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;
	int				check;

	index = 0;
	check = 0;
	while (index < n)
	{
		if (*(src + index) == '\0' || check == 1)
		{
			*(dest + index) = '\0';
			check = 1;
		}
		else
			*(dest + index) = *(src + index);
		index++;
	}
	return (dest);
}
