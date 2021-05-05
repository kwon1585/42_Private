/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:51:26 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/11 01:29:37 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int rtn_p;
	int rtn_m;

	i = 1;
	rtn_p = 0;
	rtn_m = 0;
	if (length < 2)
		return (1);
	while (i < length)
	{
		if (f(tab[i], tab[i - 1]) <= 0)
			rtn_p++;
		if (f(tab[i], tab[i - 1]) >= 0)
			rtn_m++;
		i++;
	}
	if (rtn_p == length - 1 || rtn_m == length - 1)
		return (1);
	return (0);
}
