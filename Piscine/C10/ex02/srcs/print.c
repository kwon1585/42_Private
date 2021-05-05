/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:05:46 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 16:08:08 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	return ;
}

void	print_error(char *ar, char *name)
{
	print_str(basename(name));
	write(1, ": ", 2);
	print_str(ar);
	write(1, ": ", 2);
	print_str(strerror(errno));
	write(1, "\n", 1);
	errno = 0;
	return ;
}

int		print_num_error(char *ar, char *name)
{
	print_str(basename(name));
	write(1, ": illegal offset -- ", 20);
	print_str(ar);
	write(1, "\n", 1);
	errno = 0;
	return (-1);
}

void	ft_display_file(int fd, char *str, char *name, int size)
{
	int		i;
	char	c;

	i = 0;
	g_first_print = 0;
	while (read(fd, &c, 1))
	{
		if (errno)
		{
			print_error(str, name);
			return ;
		}
		if (size - i <= g_num)
			write(1, &c, 1);
		i++;
	}
	return ;
}

void	stdin_mode(int fd)
{
	long long	idx;
	int			tmp;

	if (g_num == 0)
	{
		while (read(fd, g_buf, 1))
			if (errno)
				return ;
	}
	else
	{
		idx = 0;
		while (read(fd, &g_buf[(idx % g_num)], 1))
		{
			if (errno)
				return ;
			++idx;
		}
		tmp = idx % g_num;
		if (idx >= g_num)
			write(1, g_buf + tmp, g_num - tmp);
		write(1, g_buf, tmp);
	}
}
