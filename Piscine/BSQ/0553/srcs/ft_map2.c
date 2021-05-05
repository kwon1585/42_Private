#include "ft_map.h"
#include "ft_lib.h"
#include "ft_str.h"
#include "ft_error.h"

int		*ft_first_line(char *p)
{
	int		i;
	int		j;
	int		*arr;

	arr = (int*)ft_malloc(sizeof(int) * 5);
	i = 0;
	while (p[i] != '\n' && p[i])
		i++;
	if (i < 4)
		ft_error_check("Mark Size Error");
	arr[3] = p[--i];
	arr[2] = p[--i];
	arr[1] = p[--i];
	if (arr[1] == arr[2] || arr[2] == arr[3] || arr[3] == arr[1])
		ft_error_check("Same Mark Error");
	j = 0;
	while (j < i)
	{
		if (p[j] > '9' || p[j] < '0')
			ft_error_check("Line Parsing Error");
		arr[0] *= 10;
		arr[0] += p[j++] - '0';
	}
	return (arr);
}

int		ft_line_len(char *line, char charset)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != charset)
		i++;
	return (i);
}

void	ft_print_map(int **map, int *arr)
{
	int		y;
	int		x;

	y = 0;
	while (y < arr[0])
	{
		x = 0;
		while (x < arr[4])
		{
			ft_putchar(ft_convert(map[y][x], arr, 1));
			x++;
		}
		ft_putstr("\n");
		y++;
	}
}

void	ft_map_func(int fd)
{
	char	*p;
	int		**map;
	int		*saved_yx;
	int		*arr;
	int		size;

	p = ft_read_file(fd, &size);
	arr = ft_first_line(p);
	map = ft_make_map(p, arr);
	saved_yx = ft_solve_map(map, arr);
	if (g_max < 2)
		saved_yx = ft_map_gmax_zero(map, arr, saved_yx);
	ft_restore_map(map, saved_yx);
	ft_print_map(map, arr);
	ft_free_all(map, p, saved_yx, arr);
}

int		ft_convert(char c, int *arr, int rev)
{
	if (!rev)
	{
		if (c == arr[1])
			return (1);
		else if (c == arr[2])
			return (0);
		else
			ft_error_check("convert Error");
	}
	else
	{
		if (c == 0)
			return (arr[2]);
		else if (c < g_max)
			return (arr[1]);
		else if (c == g_max)
			return (arr[3]);
		else
			ft_error_check("Life is unfair");
	}
	return (0);
}
