/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:21:20 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 17:33:16 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		write_chess(int *chess)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < 10)
	{
		tmp = *(chess + i) + 48;
		write(1, &tmp, 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int		queen(int n, int *chess, int *rtn)
{
	int i;
	int j;
	int is_okay;

	i = -1;
	if (n == 10)
		return (write_chess(chess));
	while (++i < 10)
	{
		j = 0;
		is_okay = 1;
		chess[n] = i;
		while (j < n)
		{
			if (chess[j] == i || j + chess[j] == n + i || j - chess[j] == n - i)
			{
				is_okay = 0;
				break ;
			}
			j++;
		}
		if (is_okay == 1)
			*rtn += queen(n + 1, chess, rtn);
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int rtn;
	int chess[10];

	i = 0;
	rtn = 0;
	while (i < 10)
		chess[i++] = -1;
	queen(0, chess, &rtn);
	return (rtn);
}
