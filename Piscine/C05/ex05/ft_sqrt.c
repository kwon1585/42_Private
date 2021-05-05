/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:20:56 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 20:02:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long rtn;
	long tmp;

	rtn = 0;
	while (rtn <= nb)
	{
		tmp = rtn * rtn;
		if (tmp == nb)
			return (rtn);
		if (tmp > nb)
			return (0);
		rtn++;
	}
	return (0);
}
