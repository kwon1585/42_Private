/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:45:42 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 22:16:54 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		check_num_three(char *str)
{
	int i;

	i = 0;
	if (str[0] == '0' && str[1] == '\0')
		return (1);
	while (*(str + i))
	{
		if (*(str + i) != '0')
			return (1);
		i++;
	}
	return (0);
}

int		check_num(char *str, int size)
{
	int	i;

	i = 0;
	if ((str[0] == '0' && str[1] != '\0') || size >= 40)
	{
		free(str);
		return (1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}
