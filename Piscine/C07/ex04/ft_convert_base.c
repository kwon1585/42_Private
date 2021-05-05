/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:23:13 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/10 10:14:27 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_atoi_base(char *base);

int		ft_atoi_base(char *str, char *base, int len);

int		get_rtn_len(int value, int base_len)
{
	int				size;
	unsigned int	value_tmp;

	size = 1;
	if (value < 0)
	{
		value_tmp = value * (-1);
		value_tmp++;
		size++;
	}
	else
		value_tmp = value;
	while (value_tmp / base_len)
	{
		size++;
		value_tmp = value_tmp / base_len;
	}
	return (size);
}

void	change_base_to(char *rtn, char *base, unsigned int value, int len)
{
	*rtn = base[value % len];
	rtn--;
	if (value / len)
		change_base_to(rtn, base, value / len, len);
	else
		return ;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				value;
	unsigned int	value_tmp;
	int				rtn_len;
	int				base_len;
	char			*rtn;

	base_len = check_atoi_base(base_from);
	if (base_len <= 1)
		return (NULL);
	value = ft_atoi_base(nbr, base_from, base_len);
	base_len = check_atoi_base(base_to);
	if (base_len <= 1)
		return (NULL);
	rtn_len = get_rtn_len(value, base_len);
	rtn = (char *)malloc(sizeof(char) * (rtn_len + 1));
	rtn[rtn_len] = 0;
	if (value < 0)
	{
		*rtn = '-';
		value_tmp = value * (-1);
	}
	else
		value_tmp = value;
	change_base_to(rtn + rtn_len - 1, base_to, value_tmp, base_len);
	return (rtn);
}
