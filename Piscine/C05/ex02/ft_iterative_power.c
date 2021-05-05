/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:20:30 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 00:30:04 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int rtn;

	rtn = 1;
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		rtn *= nb;
		power--;
	}
	return (rtn);
}
