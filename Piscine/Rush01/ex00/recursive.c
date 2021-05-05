/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:27:40 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/10 14:21:56 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row(int **ans, int *side, struct s_point p)
{
	int i;
	int temp;
	int max;

	i = -1;
	max = 0;
	temp = 0;
	while (++i <= p.col)
	{
		if (i < p.col && ans[p.row][i] == ans[p.row][p.col])
			return (1);
		if (max < ans[p.row][i])
		{
			max = ans[p.row][i];
			temp++;
		}
	}
	if (p.col == 3)
	{
		if (side[p.row + 8] != temp)
			return (1);
	}
	else if (side[p.row + 8] < temp)
		return (1);
	return (0);
}

int	check_col(int **ans, int *side, struct s_point p)
{
	int i;
	int temp;
	int max;

	i = -1;
	max = 0;
	temp = 0;
	while (++i <= p.row)
	{
		if (i < p.row && ans[i][p.col] == ans[p.row][p.col])
			return (1);
		if (max < ans[i][p.col])
		{
			max = ans[i][p.col];
			temp++;
		}
	}
	if (p.row == 3)
	{
		if (side[p.col] != temp)
			return (1);
	}
	else if (side[p.col] < temp)
		return (1);
	return (0);
}

int	finish_row(int **ans, int *side, struct s_point p)
{
	int i;
	int temp;
	int max;

	i = 3;
	max = 0;
	temp = 0;
	if (p.col != 3)
		return (0);
	while (i >= 0)
	{
		if (max < ans[p.row][i])
		{
			max = ans[p.row][i];
			temp++;
		}
		i--;
	}
	if (side[p.row + 12] != temp)
		return (1);
	return (0);
}

int	finish_col(int **ans, int *side, struct s_point p)
{
	int i;
	int temp;
	int max;

	i = 3;
	max = 0;
	temp = 0;
	if (p.row != 3)
		return (0);
	while (i >= 0)
	{
		if (max < ans[i][p.col])
		{
			max = ans[i][p.col];
			temp++;
		}
		i--;
	}
	if (side[p.col + 4] != temp)
		return (1);
	return (0);
}

int	put_data(int **ans, int *side, struct s_point p, int num)
{
	int				i;
	int				rtn;
	struct s_point	p_tmp;

	i = 1;
	ans[p.row][p.col] = num;
	if (check_row(ans, side, p) || check_col(ans, side, p)
			|| finish_row(ans, side, p) || finish_col(ans, side, p))
		return (0);
	if (p.row == 3 && p.col == 3)
		return (1);
	while (i <= 4)
	{
		p_tmp = make_next_struct(p);
		rtn = put_data(ans, side, p_tmp, i);
		if (rtn == 1)
			return (1);
		i++;
	}
	return (0);
}
