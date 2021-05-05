/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:49:35 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 20:50:34 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strsplit(char *str, int size, int pos)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(size + 1);
	temp[size] = 0;
	temp[0] = str[pos];
	i = 1;
	while (i < size)
	{
		temp[i] = '0';
		i++;
	}
	if (ft_strlen(temp) == 2 && temp[0] == '1')
		temp[1] = str[pos + 1];
	return (temp);
}

int		ft_strstr(char *src, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != src[i])
			return (0);
		i++;
	}
	if ('0' <= src[i] && src[i] <= '9')
		return (0);
	return (1);
}
