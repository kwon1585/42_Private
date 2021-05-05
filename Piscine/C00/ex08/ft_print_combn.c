/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:01:50 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/21 00:10:34 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_last(int n)
{
	int rtn;
	int ten;
	int plus;

	rtn = 0;
	ten = 1;
	plus = 9;
	while (n > 0)
	{
		rtn = rtn + plus * ten;
		ten = ten * 10;
		plus--;
		n--;
	}
	return (rtn);
}

int		is_okay(int num, int last)
{
	if (num == 0)
		return (1);
	else if ((num % 10) < last)
	{
		last = num % 10;
		num = num / 10;
		return (is_okay(num, last));
	}
	else
		return (0);
}

void	print_number(int with_zero, int num_ogn, int is_last)
{
	int		index;
	int		num;
	char	print[20];

	index = 2;
	num = num_ogn;
	print[0] = ' ';
	print[1] = ',';
	while (num >= 10)
	{
		print[index] = (char)(num % 10 + 48);
		num = num / 10;
		index++;
	}
	print[index] = (char)(num + 48);
	if (with_zero == 1 && num_ogn != 0)
		print[++index] = '0';
	while (index >= 0)
	{
		if (is_last == 0 || (is_last == 1 && index > 1))
			write(1, print + index, 1);
		index--;
	}
}

void	ft_print_combn(int n)
{
	int size;
	int num;
	int	last;

	size = 1;
	last = is_last(n);
	while (n-- != 0)
		size = size * 10;
	num = size / 100;
	while (num < size)
	{
		if (is_okay(num, 10))
		{
			if (num < size / 10)
				print_number(1, num, 0);
			else if (num == last)
			{
				print_number(0, num, 1);
				num = size;
			}
			else
				print_number(0, num, 0);
		}
		num++;
	}
}
