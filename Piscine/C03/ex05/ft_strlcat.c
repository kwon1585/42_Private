/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:45:42 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/25 00:39:56 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_i;
	unsigned int src_i;
	unsigned int cat_i;

	dest_i = 0;
	src_i = 0;
	while (*(dest + dest_i) != '\0')
		dest_i++;
	cat_i = dest_i;
	while (*(src + src_i) != '\0' && cat_i + 1 < size)
	{
		*(dest + cat_i) = *(src + src_i);
		src_i++;
		cat_i++;
	}
	*(dest + cat_i) = '\0';
	src_i = 0;
	while (*(src + src_i) != '\0')
		src_i++;
	if (size < dest_i)
		return (src_i + size);
	else
		return (src_i + dest_i);
}
