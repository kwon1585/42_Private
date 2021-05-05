/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 04:06:03 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 23:54:00 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int		print_zero(void)
{
	write(1, "0\n", 2);
	return (0);
}

void	print_num(int num)
{
	char c;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num == 0)
		return ;
	print_num(num / 10);
	c = num % 10 + 48;
	write(1, &c, 1);
	return ;
}

int		(*match_operator(char c))(int, int)
{
	if (c == '+')
		return (add);
	else if (c == '-')
		return (diff);
	else if (c == '*')
		return (multiple);
	else if (c == '/')
		return (divide);
	else if (c == '%')
		return (modular);
	else
		return (0);
}

int		is_calculator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (0);
	else
		return (1);
}

int		main(int argc, char *argv[])
{
	int	num[2];
	int	ans;
	int	(*cal_num)(int, int);

	if (argc != 4)
		return (0);
	if (argv[2][1] != '\0' || is_calculator(argv[2][0]))
		return (print_zero());
	num[0] = ft_atoi(argv[1]);
	num[1] = ft_atoi(argv[3]);
	cal_num = match_operator(argv[2][0]);
	if (num[1] == 0 && (cal_num == divide || cal_num == modular))
	{
		if (cal_num == divide)
			write(1, "Stop : division by zero\n", 24);
		else
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ans = (*cal_num)(num[0], num[1]);
	if (ans == 0)
		return (print_zero());
	print_num(ans);
	write(1, "\n", 1);
	return (0);
}
