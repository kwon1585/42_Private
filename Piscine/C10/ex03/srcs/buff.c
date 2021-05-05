/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:55:58 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/16 05:40:36 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	copy_buff(void)
{
	int i;

	i = 0;
	while (i < 16)
	{
		g_buff2[i] = g_buff[i];
		i++;
	}
	g_buff[16] = 0;
}

int		cmp_buff(void)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (g_buff2[i] != g_buff[i])
			return (0);
		i++;
	}
	return (1);
}
