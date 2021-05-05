/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:43:06 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 01:43:36 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		f;
	char	c;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		f = open(argv[1], O_RDONLY);
		if (f < 0)
			write(1, "Cannot read file.\n", 18);
		else
			while (read(f, &c, 1))
				write(1, &c, 1);
	}
	return (0);
}
