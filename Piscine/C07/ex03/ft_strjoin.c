/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:47:36 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/10 10:57:22 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(char *strs)
{
	int i;

	i = 0;
	while (*(strs + i))
		i++;
	return (i);
}

char	*put_data(int size, char *rtn, char **strs, char *sep)
{
	int i;
	int j;
	int rtn_i;

	i = 0;
	rtn_i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			*(rtn + rtn_i++) = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			*(rtn + rtn_i++) = *(sep + j++);
		i++;
	}
	rtn[rtn_i] = '\0';
	return (rtn);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len_sum;
	char	*rtn;

	i = 0;
	len_sum = 1;
	if (size == 0)
	{
		rtn = (char *)malloc(sizeof(char) * 1);
		*rtn = '\0';
		return (rtn);
	}
	len_sum += get_length(sep) * (size - 1);
	while (i < size)
		len_sum += get_length(*(strs + i++));
	rtn = (char *)malloc(sizeof(char) * len_sum);
	rtn = put_data(size, rtn, strs, sep);
	return (rtn);
}
