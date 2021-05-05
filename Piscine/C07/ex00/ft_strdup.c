/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:46:54 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 06:12:48 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*rtn;

	size = 0;
	while (*(src + size) != '\0')
		size++;
	rtn = (char *)malloc(sizeof(char) * size);
	while (size >= 0)
	{
		*(rtn + size) = *(src + size);
		size--;
	}
	return (rtn);
}
