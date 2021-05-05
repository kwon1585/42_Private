/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:16:35 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 20:26:45 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int i;
	int j;
	int rtn;

	i = 0;
	rtn = 0;
	while (*(base + i) != '\0')
	{
		j = i + 1;
		while (*(base + j) != '\0')
		{
			if (*(base + i) == *(base + j))
				return (-1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (-1);
		i++;
		rtn++;
	}
	return (rtn);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len;
	int				i;
	unsigned int	nbr_cp;
	char			ans[100];

	i = 0;
	len = check_base(base);
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_cp = nbr * -1;
	}
	else
		nbr_cp = nbr;
	while (nbr_cp / len != 0)
	{
		ans[i++] = base[nbr_cp % len];
		nbr_cp /= len;
	}
	ans[i] = base[nbr_cp];
	while (i >= 0)
		write(1, ans + i--, 1);
}
