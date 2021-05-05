/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:41:23 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 22:17:12 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*get_num(char *str, int *len)
{
	int		i;
	char	*num;

	i = 0;
	while (*(str + (*len)))
		(*len)++;
	num = (char *)malloc(sizeof(char) * (*len + 1));
	num[*len] = 0;
	while (*str)
	{
		num[i++] = *str;
		str++;
	}
	return (num);
}

char	*get_line(int fd)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * 1000);
	while (1)
	{
		read(fd, rtn + i, 1);
		if (rtn[i] == '\0')
		{
			free(rtn);
			return (0);
		}
		if (rtn[i] == '\n')
			break ;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
