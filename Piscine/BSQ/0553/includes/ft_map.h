#ifndef FT_MAP_H
# define FT_MAP_H

int		**ft_make_map(char *p, int *arr);
int		ft_check_pos(int y, int x, int **map);
int		*ft_solve_map(int **map, int *arr);
void	ft_restore_map(int **map, int *saved_yx);
int		*ft_map_gmax_zero(int **map, int *arr, int *saved_yx);

int		*ft_first_line(char *p);
int		ft_line_len(char *line, char charset);
int		ft_convert(char c, int *arr, int rev);
void	ft_print_map(int **map, int *arr);
void	ft_map_func(int fd);

int		g_max;
int		g_line;

#endif
