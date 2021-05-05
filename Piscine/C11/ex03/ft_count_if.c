/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:49:31 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/11 01:29:22 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int rtn;

	i = 0;
	rtn = 0;
	while (i < length)
		if (f(tab[i++]))
			rtn++;
	return (rtn);
}
