/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:12 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/22 19:47:41 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(int num)
{
	char ten;
	char one;

	ten = (char)(num / 10 + 48);
	one = (char)(num % 10 + 48);
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb2(void)
{
	int		front;
	int		back;
	char	sym[2];

	sym[0] = ',';
	sym[1] = ' ';
	front = 0;
	back = 1;
	while (front <= 98)
	{
		back = front + 1;
		while (back <= 99)
		{
			print_char(front);
			write(1, sym + 1, 1);
			print_char(back);
			if (front != 98)
				write(1, sym, 2);
			back++;
		}
		front++;
	}
}
