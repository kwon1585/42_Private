/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:42:41 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 20:26:06 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		index;
	char	minus;
	char	print[20];

	index = 0;
	minus = '-';
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, &minus, 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
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
