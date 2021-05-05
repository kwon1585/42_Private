#include "ft_str.h"
#include "ft_lib.h"
#include "ft_map.h"
#include "ft_error.h"
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;

	i = argc == 1 ? 0 : 1;
	while (i < argc)
	{
		fd = argc == 1 ? 0 : open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_error_check("File Open Error");
		ft_map_func(fd);
		i++;
		if (i < argc)
			ft_putstr("\n");
		close(fd);
	}
}
