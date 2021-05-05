/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:58:22 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 16:06:39 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int		check_size(int fd)
{
	int		rtn;
	char	c;

	rtn = 0;
	while (read(fd, &c, 1))
		rtn++;
	return (rtn);
}

void	sep_files(int index, char *str)
{
	if (index != 3 && g_first_print == 0)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	print_str(str);
	write(1, " <==\n", 5);
}

int		ft_atoi(char *str, char *name)
{
	int		rtn;
	char	*tmp;

	g_first_print = 1;
	rtn = 0;
	tmp = str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (print_num_error(str, name));
		rtn = rtn * 10 + (*str - 48);
		str++;
	}
	return (rtn);
}

int		main(int argc, char *argv[])
{
	int i;
	int size;
	int fd;

	i = 2;
	g_num = ft_atoi(argv[2], argv[0]);
	g_buf = (char *)malloc(g_num);
	if (argc == 3 && g_num >= 0)
		stdin_mode(0);
	while (++i < argc && g_num >= 0)
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			print_error(argv[i], argv[0]);
		else
		{
			if (argc > 4)
				sep_files(i, argv[i]);
			size = check_size(fd);
			close(fd);
			fd = open(argv[i], O_RDONLY);
			ft_display_file(fd, argv[i], argv[0], size);
			close(fd);
		}
	}
	return (0);
}
