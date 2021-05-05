/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:29:04 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 21:04:20 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	print_ans(int **ans)
{
	int		i;
	int		j;
	char	print;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			print = ans[i][j] + 48;
			write(1, &print, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

int		input_error(int *side, char *num)
{
	int i;

	i = 0;
	while (i < 31)
	{
		if (num[i] == '\0')
			return (1);
		if (i % 2 == 0)
		{
			if (num[i] < '1' || num[i] > '4')
				return (1);
			else
				side[i / 2] = num[i] - 48;
		}
		else
		{
			if (num[i] != ' ')
				return (1);
		}
		i++;
	}
	if (num[i] != '\0')
		return (1);
	return (0);
}

void	rush_init(int **ans, int *side)
{
	int				i;
	int				rtn;
	struct s_point	p;

	i = 1;
	p.row = 0;
	p.col = 0;
	while (i <= 4)
	{
		rtn = put_data(ans, side, p, i);
		if (rtn == 1)
		{
			print_ans(ans);
			return ;
		}
		i++;
	}
	print_error();
	return ;
}

int		main(int argc, char *argv[])
{
	int				i;
	int				side[16];
	int				**ans;

	i = 0;
	if (argc != 2 || input_error(side, argv[1]))
		return (print_error());
	if ((ans = (int **)malloc(sizeof(int *) * 4)) == NULL)
		return (print_error());
	while (i < 4)
		if ((ans[i++] = (int *)malloc(sizeof(int) * 4)) == NULL)
		{
			i = i - 2;
			while (i >= 0)
				free(ans[i--]);
			free(ans);
			return (print_error());
		}
	rush_init(ans, side);
	i = 0;
	while (i < 4)
		free(ans[i++]);
	free(ans);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
