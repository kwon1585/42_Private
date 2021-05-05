/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:25:59 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/24 15:07:31 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_contents_dec(unsigned char *str, int num)
{
	int		i;
	int		time;
	char	space;

	i = 0;
	space = ' ';
	time = (16 - num) * 2 + (16 - num) / 2 + num % 2;
	while (time != 0 && num != 16 && num != 0)
	{
		write(1, &space, 1);
		time--;
	}
	while (i < num)
	{
		if (*(str + i) < 32 || *(str + i) > 126)
			write(1, ".", 1);
		else
			write(1, str + i, 1);
		i++;
	}
}

void	print_contents_hex(char *hex, unsigned char *str, int num)
{
	int				index;
	unsigned char	temp;

	index = 0;
	temp = *str;
	while (index++ != num)
	{
		if (temp / 16 >= 10)
			hex[0] = temp / 16 + 87;
		else
			hex[0] = temp / 16 + 48;
		if (temp % 16 >= 10)
			hex[1] = temp % 16 + 87;
		else
			hex[1] = temp % 16 + 48;
		if (index % 2 == 0)
			write(1, hex, 3);
		else
			write(1, hex, 2);
		temp = *(str + index);
	}
}

void	print_address_hex(char *add, unsigned char *str, int is_last)
{
	int		index;
	int		temp;
	long	num;

	num = (long)str;
	index = 2;
	while (index < 18 && is_last != 0)
	{
		if (num != 0)
		{
			temp = num % 16;
			if (temp >= 10)
				add[index++] = temp + 87;
			else
				add[index++] = temp + 48;
		}
		else
			add[index++] = '0';
		num = num / 16;
	}
	while (index > 0 && is_last != 0)
		write(1, add + --index, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				line_num;
	int				is_last;
	unsigned char	*addr_tmp;
	char			add[20];
	char			hex[3];

	add[0] = ' ';
	add[1] = ':';
	add[18] = '0';
	add[19] = '\n';
	hex[2] = ' ';
	is_last = 16;
	line_num = 0;
	addr_tmp = (unsigned char *)addr;
	while ((unsigned int)line_num <= (size / 16))
	{
		if (line_num == (size / 16))
			is_last = size % 16;
		print_address_hex(add, addr_tmp + (line_num * 16), is_last);
		print_contents_hex(hex, addr_tmp + (line_num * 16), is_last);
		print_contents_dec(addr_tmp + (line_num * 16), is_last);
		write(1, add + 19, 1);
		line_num++;
	}
	return (addr);
}
