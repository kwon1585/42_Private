/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:25:24 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/21 03:50:54 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int front;
	int back;
	int temp;

	front = 0;
	back = size - 1;
	while (front < back)
	{
		temp = *(tab + front);
		*(tab + front) = *(tab + back);
		*(tab + back) = temp;
		front++;
		back--;
	}
}
