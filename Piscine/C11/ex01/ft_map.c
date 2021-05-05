/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:33:25 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/11 01:16:00 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int	*rtn;

	i = 0;
	if ((rtn = (int *)malloc(sizeof(int) * length)) == NULL)
		return (0);
	while (i < length)
	{
		rtn[i] = f(tab[i]);
		i++;
	}
	return (rtn);
}
