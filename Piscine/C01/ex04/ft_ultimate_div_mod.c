/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:12:46 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/21 05:23:37 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int a_prime;
	int b_prime;

	a_prime = *a;
	b_prime = *b;
	*a = a_prime / b_prime;
	*b = a_prime % b_prime;
}
