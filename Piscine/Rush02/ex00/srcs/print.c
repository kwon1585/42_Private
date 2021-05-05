/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:41:55 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 22:02:08 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		print_error(int n)
{
	if (n == 0)
		write(1, "Argument Error\n", 15);
	else if (n == 1)
		write(1, "File Error\n", 11);
	else if (n == 3)
		write(1, "Dict Error\n", 11);
	else if (n == 2)
		write(1, "error\n", 6);
	return (0);
}

int		print_unit(int fd, int len, int size)
{
	char	*now_line;
	char	*now_line_tmp;

	while (len != 1)
	{
		size = 0;
		now_line = get_line(fd);
		if (!(now_line_tmp = now_line))
			return (print_error(3));
		while (*now_line != ':' && *now_line != '\0')
			if (*(now_line++) != ' ')
				size++;
		now_line++;
		if (size == len)
		{
			while (*now_line == ' ' && *now_line != '\0')
				now_line++;
			while (*now_line != '\0')
				push(*(now_line++));
			free(now_line_tmp);
			break ;
		}
		free(now_line_tmp);
	}
	return (1);
}

char	*make_three(char *num, int len)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		rtn[i] = num[i];
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}

void	print_three(char *str, int fd)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
	{
		fd = re_open(fd);
		ft_changestr(str, fd);
		return ;
	}
	i = -1;
	while (++i < len)
	{
		fd = re_open(fd);
		temp = ft_strsplit(str, len - i, i);
		ft_numbers(temp, len - i, str);
		free(temp);
		if (len - i == 2 && str[i] == '1')
			break ;
	}
}

int		print_num(int fd, char *num, char *num_three, int len)
{
	if (check_num_three(num_three))
	{
		print_three(num_three, fd);
		if (g_argc == -1)
			return (0);
		if (len != 1)
			push(' ');
		fd = re_open(fd);
		if (!print_unit(fd, len, 0))
			return (0);
	}
	num += ft_strlen(num_three);
	free(num_three);
	len -= 3;
	if (*num != '\0')
	{
		if (check_num_three(num_three = make_three(num, 3)))
			push(' ');
		fd = re_open(fd);
		return (print_num(fd, num, num_three, len));
	}
	return (1);
}
