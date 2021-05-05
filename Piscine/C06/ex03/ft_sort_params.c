/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:06:07 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 01:42:25 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_argv(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, argv[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		comp_ascii(char *ar1, char *ar2)
{
	int i;

	i = 0;
	while (ar1[i] != '\0' || ar2[i] != '\0')
	{
		if (ar1[i] > ar2[i])
			return (1);
		else if (ar1[i] < ar2[i])
			return (0);
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (comp_ascii(argv[i], argv[j]))
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	print_argv(argc, argv);
	return (0);
}
