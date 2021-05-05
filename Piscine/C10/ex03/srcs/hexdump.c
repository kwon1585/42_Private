/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:17:19 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 11:28:23 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int		is_option(char *str)
{
	if (str == 0)
		return (0);
	if (str[0] == 45 && str[1] == 67 && str[2] == 0)
		return (1);
	return (0);
}

void	read_data(int fd)
{
	while (read(fd, g_buff + g_idx, 1))
	{
		g_check = 1;
		if (g_idx == 15)
		{
			print_buff(0);
			g_idx = 0;
			g_line++;
			copy_buff();
		}
		else
			g_idx++;
	}
	if (fd > 0)
		close(fd);
}

void	init_global(void)
{
	g_line = 0;
	g_idx = 0;
	g_star = 0;
	g_check = 0;
}

int		main(int argc, char *argv[])
{
	int		i;
	int		fd;

	i = 1;
	init_global();
	g_is_c = is_option(argc != 1 ? argv[1] : 0);
	if (argc == 1 || (g_is_c && argc == 2))
		read_data(0);
	while (i + g_is_c < argc)
	{
		if ((fd = open(argv[i + g_is_c], O_RDONLY)) < 0)
			print_error(argv[i + g_is_c], argv[0]);
		else
			read_data(fd);
		i++;
		if (!g_check && (i + g_is_c == argc))
		{
			errno = 9;
			print_error(argv[argc - 1], argv[0]);
		}
	}
	g_buff[g_idx] = 0;
	print_buff(1);
	return (0);
}
