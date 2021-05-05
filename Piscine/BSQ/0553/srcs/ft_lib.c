/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:37:29 by dongkim           #+#    #+#             */
/*   Updated: 2021/03/18 08:16:16 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include "ft_str.h"

void	*ft_malloc(int size)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

char	*ft_realloc(char *p, int bef_size, int size)
{
	char	*ret;
	int		i;

	if (p == 0)
	{
		ret = ft_malloc(sizeof(char) * (size + 1));
		ret[size] = 0;
		return (ret);
	}
	ret = ft_malloc(sizeof(char) * size);
	i = 0;
	while (i < bef_size)
	{
		ret[i] = p[i];
		i++;
	}
	ret[i] = 0;
	free(p);
	return (ret);
}

void	ft_free_all(int **map, char *p, int *saved_yx, int *arr)
{
	int		i;

	i = 0;
	while (i < arr[0])
		free(map[i++]);
	free(map);
	free(arr);
	free(p);
	free(saved_yx);
}

char	*ft_read_file(int fd, int *filesize)
{
	char	buf[100000];
	char	*p;
	int		rb;
	int		i;

	*filesize = 0;
	p = 0;
	rb = 1;
	i = 0;
	while (i < 100000)
		*(buf + i++) = 1;
	while (rb)
	{
		rb = read(fd, buf, 100000);
		p = ft_realloc(p, *filesize, (*filesize) + rb + 1);
		ft_strncpy(&p[*filesize], buf, rb);
		(*filesize) += rb;
	}
	return (p);
}
