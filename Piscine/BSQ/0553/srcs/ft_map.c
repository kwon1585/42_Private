#include "ft_map.h"
#include "ft_lib.h"
#include "ft_str.h"
#include "ft_error.h"

int		**ft_make_map(char *p, int *arr)
{
	int		**map;
	int		line;
	int		idx;
	int		size;
	int		i;

	map = ft_malloc(sizeof(int *) * arr[0]);
	idx = ft_line_len(p, '\n') + 1;
	line = 0;
	size = ft_line_len(&p[idx], '\n');
	arr[4] = size;
	while (p[idx])
	{
		if (size != ft_line_len(&p[idx], '\n'))
			ft_error_check("One Line Length Error");
		map[line] = ft_malloc(sizeof(int) * size);
		i = 0;
		while (i < size)
			map[line][i++] = ft_convert(p[idx++], arr, 0);
		idx++;
		line++;
	}
	if (line > arr[0])
		ft_error_check("LINE Error!!");
	return (map);
}

int		ft_check_pos(int y, int x, int **map)
{
	int		min;

	if (map[y][x] == 0)
		return (0);
	min = map[y - 1][x - 1];
	min = map[y - 1][x] < min ? map[y - 1][x] : min;
	min = map[y][x - 1] < min ? map[y][x - 1] : min;
	return (min + 1);
}

int		*ft_solve_map(int **map, int *arr)
{
	int		x;
	int		y;
	int		*saved_yx;

	g_max = 0;
	saved_yx = ft_malloc(sizeof(int) * 2);
	y = 1;
	while (y < arr[0])
	{
		x = 1;
		while (x < arr[4])
		{
			map[y][x] = ft_check_pos(y, x, map);
			if (g_max < map[y][x])
			{
				saved_yx[0] = y;
				saved_yx[1] = x;
				g_max = map[y][x];
			}
			x++;
		}
		y++;
	}
	return (saved_yx);
}

void	ft_restore_map(int **map, int *saved_yx)
{
	int		x;
	int		y;

	y = saved_yx[0] - g_max + 1;
	x = saved_yx[1] - g_max + 1;
	while (y <= saved_yx[0])
	{
		x = saved_yx[1] - g_max + 1;
		while (x <= saved_yx[1])
		{
			map[y][x] = g_max + 1;
			x++;
		}
		y++;
	}
	g_max++;
}

int		*ft_map_gmax_zero(int **map, int *arr, int *saved_yx)
{
	int		x;
	int		y;

	y = 0;
	while (y < arr[0])
	{
		x = 0;
		while (x < arr[4])
		{
			if (map[y][x] == 1)
			{
				saved_yx[0] = y;
				saved_yx[1] = x;
				g_max = 1;
				return (saved_yx);
			}
			x++;
		}
		y++;
	}
	return (saved_yx);
}
