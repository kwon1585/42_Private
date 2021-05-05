/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:00:15 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 01:39:19 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;

	i = argc;
	i = 0;
	while (argv[0][i])
	{
		write(1, argv[0] + i, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
