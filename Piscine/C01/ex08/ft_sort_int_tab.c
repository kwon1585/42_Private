/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:56:59 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/21 05:24:45 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int	idx_1;
	int idx_2;

	idx_1 = 0;
	while (idx_1 < size)
	{
		idx_2 = idx_1 + 1;
		while (idx_2 < size)
		{
			if (*(tab + idx_1) > *(tab + idx_2))
			{
				temp = *(tab + idx_1);
				*(tab + idx_1) = *(tab + idx_2);
				*(tab + idx_2) = temp;
			}
			idx_2++;
		}
		idx_1++;
	}
}
