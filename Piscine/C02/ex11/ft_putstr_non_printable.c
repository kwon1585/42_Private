/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:25:45 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/08 22:11:16 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char num)
{
	char hex;

	if (num >= 10)
		hex = num + 87;
	else
		hex = num + 48;
	write(1, &hex, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > 31 && *(str + i) < 127)
			write(1, str + i, 1);
		else
		{
			write(1, "\\", 1);
			print_hex((unsigned char)*(str + i) / 16);
			print_hex((unsigned char)*(str + i) % 16);
		}
		i++;
	}
}
