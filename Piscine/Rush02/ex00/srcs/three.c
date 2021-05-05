/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:59:47 by jeylee            #+#    #+#             */
/*   Updated: 2021/03/14 23:00:48 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_printdict(char *buff)
{
	int i;

	i = 0;
	while (buff[i] && !('a' <= buff[i] && buff[i] <= 'z'))
		i++;
	while (buff[i] && buff[i] != '\n')
	{
		push(buff[i]);
		i++;
	}
}

void	ft_changestr(char *str, int fd)
{
	int		i;
	char	buff[1500];

	i = 0;
	read(fd, buff, 1500);
	while (buff[i])
	{
		if (buff[i] == str[0])
		{
			if (ft_strstr(&buff[i], str))
			{
				ft_printdict(&buff[i]);
				return ;
			}
		}
		while (buff[i] != '\n')
			i++;
		i++;
	}
	g_argc = -1;
	print_error(3);
}

void	ft_ctos(char c)
{
	char	*str;
	int		fd;

	fd = re_open(-1);
	str = (char *)malloc(2);
	str[0] = c;
	str[1] = 0;
	ft_changestr(str, fd);
	push(' ');
	free(str);
	close(fd);
}

void	ft_numbers(char *str, int len, char *c)
{
	int	fd;

	fd = re_open(-1);
	if (str[0] == '0')
	{
		close(fd);
		return ;
	}
	if (len == 3)
	{
		ft_ctos(str[0]);
		ft_changestr("100", fd);
		if (c[1] != '0' || c[2] != '0')
			push(' ');
	}
	else if (len == 2)
	{
		ft_changestr(str, fd);
		if (c[ft_strlen(c) == 2 ? 1 : 2] != '0' && str[0] != '1')
			push(' ');
	}
	else
		ft_changestr(str, fd);
}
