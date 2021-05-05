/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:20:03 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 17:22:34 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int rtn;

	rtn = 1;
	if (nb < 0)
		return (0);
	while (nb >= 1)
	{
		rtn *= nb;
		nb--;
	}
	return (rtn);
}
