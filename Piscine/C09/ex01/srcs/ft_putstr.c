/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:28:20 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/09 05:04:59 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (*(str + index) != '\0')
	{
		write(1, str + index, 1);
		index++;
	}
}
