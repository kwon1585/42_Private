/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:20:05 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/08 21:37:31 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	write_size(int size)
{
	int		i;
	char	arr[20];

	i = 0;
	while ((size / 10) != 0)
	{
		arr[i] = (size % 10) + 48;
		size = size / 10;
		i++;
	}
	arr[i] = size + 48;
	while (i >= 0)
	{
		write(1, arr + i, 1);
		i--;
	}
	write(1, "\n", 1);
}

void	write_copy(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		write_size(par[i].size);
		write_copy(par[i].copy);
		i++;
	}
}
