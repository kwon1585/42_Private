#include <stdlib.h>
#include "ft_str.h"

void	ft_error_check(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(-1);
}
