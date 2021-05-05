/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:41:48 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/08 21:32:31 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					get_len(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void				copy_str(t_stock_str *rtn, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		rtn->copy[i] = rtn->str[i];
		i++;
	}
	rtn->copy[len] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str *rtn;

	i = 0;
	rtn = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (rtn == NULL)
		return (0);
	rtn[ac].str = 0;
	while (i < ac)
	{
		len = get_len(av[i]);
		rtn[i].size = len;
		rtn[i].str = av[i];
		rtn[i].copy = (char *)malloc(sizeof(char) * (len + 1));
		copy_str(rtn + i, len);
		i++;
	}
	return (rtn);
}
