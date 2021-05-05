/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:02:47 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 13:43:59 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	g_argc;
char *g_dict;

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		re_open(int fd)
{
	if (fd >= 0)
		close(fd);
	if (g_argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(g_dict, O_RDONLY);
	return(fd);
}


char	*get_num(char *str, int *len)
{
	int		i;
	char	*num;
	
	i = 0;
	while (*(str + (*len)))
		(*len)++;
	num = (char *)malloc(sizeof(char) * (*len + 1));
	num[*len] = 0;
	while(*str)
	{
		num[i++] = *str;
		str++;
	}
	return (num);
}

char	*get_line(int fd)
{
	int		i;
	char	*rtn;
	
	i = 0;
	rtn = (char *)malloc(sizeof(char) * 1000);
	while(1)
	{
		if(read(fd, rtn + i, 1) == -1)
			return (0);
		if(rtn[i] == '\n')
			break;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

void	print_unit(int fd, int len)
{
	int		size;
	char	*now_line;
	char	*now_line_tmp;

	if (len == 1)
		return ;
	while (1)
	{
		size = 0;
		now_line = get_line(fd);
		if (!now_line)
			return ;
		now_line_tmp = now_line;
		if (*now_line != '\0')
			while (*now_line != ':')
			{
				now_line++;
				size++;
			}
			if (size == len)
			{
				now_line++;
				while (*now_line)
				{
					if (*now_line != ' ')
						write(1, now_line, 1);
					now_line++;
				}
				write(1, " ", 1);
				break ;
			}
		free(now_line_tmp);
	}
}

void	print_three(char *num, int len)
{
	write(1, num, len);
	if (*(num + len) != '\0')
		write(1, " ", 1);
}

void	print_num(int fd, char *num, int len)
{
	int next;
	int	len_to_find;
	
	if (*num == '\0')
		return ;
	len_to_find = (len % 3 != 0) ? len - (len % 3) + 1 : len - 2;	
	print_three(num, len - len_to_find + 1);
	print_unit(fd, len_to_find);
	next = len - len_to_find + 1;
	len -= next;
	num += next;
	fd = re_open(fd);
	print_num(fd, num, len);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		num_len;
	char	*num;

	g_argc = argc;
	if (argc < 2 || argc > 3)
		return (print_error());
	if (argc == 3)
		g_dict = argv[1];
	fd = re_open(-1);
	if (fd < 0)
		return (print_error());
	//make_dict()
	fd = re_open(fd);
	num = get_num(argv[argc - 1], &num_len);
	print_num(fd, num, num_len);

	free(num);
}

