/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:56:31 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/10 10:19:29 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_sep(char *str, char *charset)
{
	int i;
	int j;
	int rtn;

	i = 0;
	rtn = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				rtn++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (rtn);
}

int		is_sptr(char a, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		*sptr_index(char *str, char *charset, int *idx)
{
	int i;
	int idx_i;

	i = 0;
	idx_i = 1;
	idx[0] = -1;
	while (str[i] != '\0')
	{
		if (is_sptr(str[i], charset))
			idx[idx_i++] = i;
		i++;
	}
	idx[idx_i] = i;
	return (idx);
}

char	**put_data_split(char **rtn, char *str, int *idx)
{
	int	i;
	int j;
	int diff;
	int cpy_i;

	i = 1;
	j = 0;
	while (idx[i] != -2)
	{
		cpy_i = 1;
		diff = idx[i] - idx[i - 1];
		if (diff != 1)
		{
			rtn[j] = (char *)malloc(sizeof(char) * (diff));
			rtn[j][diff - 1] = 0;
			while (cpy_i < diff)
			{
				rtn[j][cpy_i - 1] = str[idx[i - 1] + cpy_i];
				cpy_i++;
			}
			j++;
		}
		i++;
	}
	return (rtn);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		num;
	int		*idx;
	char	**rtn;

	i = 1;
	num = count_sep(str, charset) + 2;
	idx = (int *)malloc(sizeof(int) * (num + 1));
	idx[num] = -2;
	idx = sptr_index(str, charset, idx);
	while (idx[i] != -2)
	{
		if (idx[i] - idx[i - 1] == 1)
			num--;
		i++;
	}
	rtn = (char **)malloc(sizeof(char *) * num);
	rtn[num - 1] = (char *)malloc(sizeof(char) * 2);
	rtn[num - 1] = 0;
	rtn = put_data_split(rtn, str, idx);
	return (rtn);
}
