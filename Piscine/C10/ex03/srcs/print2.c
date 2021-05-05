/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:03:57 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/16 05:23:15 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_error(char *ar, char *name)
{
	print_str(basename(name));
	write(1, ": ", 2);
	print_str(ar);
	write(1, ": ", 2);
	print_str(strerror(errno));
	write(1, "\n", 1);
	errno = 0;
	return ;
}
