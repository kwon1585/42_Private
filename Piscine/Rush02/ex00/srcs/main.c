/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:02:47 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 22:13:23 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		re_open(int fd)
{
	if (fd >= 0)
		close(fd);
	if (g_argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(g_dict, O_RDONLY);
	return (fd);
}

void	push(char c)
{
	if (c == '\0')
		g_ans[g_idx++] = '\n';
	g_ans[g_idx++] = c;
}

void	print_ans(void)
{
	int i;

	i = 0;
	push('\n');
	while (g_ans[i])
		write(1, g_ans + i++, 1);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		len;
	int		find;
	char	*num;
	char	*num_three;

	g_argc = argc;
	g_idx = 0;
	if (argc < 2 || argc > 3)
		return (print_error(0));
	if (argc == 3)
		g_dict = argv[1];
	fd = re_open(-1);
	if (fd < 0)
		return (print_error(1));
	num = get_num(argv[argc - 1], &len);
	if (check_num(num, len))
		return (print_error(2));
	find = (len % 3 != 0) ? len - (len % 3) + 1 : len - 2;
	num_three = make_three(num, len - find + 1);
	if (print_num(fd, num, num_three, find))
		print_ans();
	free(num);
	return (0);
}
