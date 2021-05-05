/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:58:22 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/15 14:10:23 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

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

void	ft_display_file(int fd, char *str, char *name)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (errno)
		{
			print_error(str, name);
			return ;
		}
		write(1, &c, 1);
	}
	return ;
}

int		main(int argc, char *argv[])
{
	int i;
	int fd;

	i = 1;
	if (argc == 1)
		ft_display_file(0, 0, 0);
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			print_error(argv[i], argv[0]);
		else
		{
			ft_display_file(fd, argv[i], argv[0]);
			close(fd);
		}
		i++;
	}
	return (0);
}
