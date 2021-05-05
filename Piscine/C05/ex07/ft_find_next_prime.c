/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:21:12 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 04:42:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int i;
	int comp;
	int is_prime;

	if (nb <= 2)
		return (2);
	comp = nb;
	while (1)
	{
		i = 3;
		is_prime = 1;
		if (comp % 2 == 0)
			is_prime = 0;
		while (i < 46341 && i < comp && is_prime == 1)
		{
			if (comp % i == 0)
				is_prime = 0;
			i = i + 2;
		}
		if (is_prime == 1 && comp >= nb)
			return (comp);
		comp++;
	}
}
