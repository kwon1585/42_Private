/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:25:32 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/24 15:02:28 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int cp_size;

	i = 0;
	cp_size = (int)size;
	while (*(src + i) != '\0' && i < cp_size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
