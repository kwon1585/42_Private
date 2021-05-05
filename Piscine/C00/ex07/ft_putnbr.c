/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:29:22 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/21 00:22:30 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	end_integer(int *nb)
{
	char print[20];

	*nb = 0;
	print[0] = '2';
	print[1] = '1';
	print[2] = '4';
	print[3] = '7';
	print[4] = '4';
	print[5] = '8';
	print[6] = '3';
	print[7] = '6';
	print[8] = '4';
	print[9] = '8';
	write(1, print, 10);
}

void	ft_putnbr(int nb)
{
	int		index;
	char	minus;
	char	zero;
	char	print[20];

	index = 0;
	minus = '-';
	zero = '0';
	if (nb == 0)
		write(1, &zero, 1);
	else if (nb < 0)
	{
		write(1, &minus, 1);
		if (nb == -2147483648)
			end_integer(&nb);
		nb = nb * -1;
	}
	while (nb > 0)
	{
		print[index++] = (char)(nb % 10 + 48);
		nb = nb / 10;
	}
	while (--index >= 0)
		write(1, print + index, 1);
}
