/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:47:04 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 05:49:55 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *rtn;

	i = 0;
	if (min >= max)
		return (0);
	rtn = (int *)malloc(sizeof(int) * (max - min));
	while (min != max)
	{
		*(rtn + i) = min;
		i++;
		min++;
	}
	return (rtn);
}
