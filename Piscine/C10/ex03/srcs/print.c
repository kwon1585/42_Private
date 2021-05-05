/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 03:25:51 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/16 05:23:03 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_contents_dec(unsigned char *arr)
{
	int i;

	if (g_idx == 0 || g_is_c != 1)
		return ;
	i = 0;
	write(1, "  |", 3);
	while (arr[i] != 0)
	{
		if (arr[i] < 32 || arr[i] > 126)
			write(1, ".", 1);
		else
			write(1, arr + i, 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	print_contents_hex(unsigned char *arr)
{
	int				i;
	char			hex[48];

	if (g_idx == 0)
		return ;
	i = 0;
	while (i < 48)
	{
		if ((i == 24 && g_is_c == 1) || *arr == 0)
			hex[i++] = ' ';
		else
		{
			hex[i++] = (*arr / 16 >= 10) ? *arr / 16 + 87 : *arr / 16 + 48;
			hex[i++] = (*arr % 16 >= 10) ? *arr % 16 + 87 : *arr % 16 + 48;
			hex[i++] = ' ';
			arr++;
		}
	}
	if (g_is_c == 1)
		write(1, hex, 48);
	else
	{
		write(1, hex, 47);
		write(1, "\n", 1);
	}
}

void	print_count_hex(char *count, int last)
{
	if (last == 0 && g_is_c == 1)
		write(1, count, 10);
	else if (g_is_c == 1)
		write(1, count, 8);
	else if (last == 0 && g_is_c == 0)
		write(1, count + 1, 8);
	else
		write(1, count + 1, 7);
	if (last == 1)
		write(1, "\n", 1);
}

void	count_hex(int last)
{
	int		i;
	int		num;
	char	count[10];

	i = 8;
	count[8] = ' ';
	count[9] = ' ';
	if (g_idx == 0 && last == 0)
		return ;
	num = (last != 1) ? g_line * 16 : g_line * 16 + g_idx;
	while (--i >= 0)
	{
		if (num == 0)
			count[i] = '0';
		else
			count[i] = (num % 16 >= 10) ? num % 16 + 87 : num % 16 + 48;
		num /= 16;
	}
	print_count_hex(count, last);
}

void	print_buff(int last)
{
	int				star;
	unsigned char	*arr;

	star = cmp_buff();
	if (star && !last)
	{
		if (g_star == 0)
		{
			write(1, "*\n", 2);
			g_star = 1;
		}
		return ;
	}
	if (g_line + g_idx == 0)
		return ;
	arr = (unsigned char *)g_buff;
	count_hex(0);
	print_contents_hex(arr);
	print_contents_dec(arr);
	if (last)
		count_hex(last);
	g_star = 0;
}
