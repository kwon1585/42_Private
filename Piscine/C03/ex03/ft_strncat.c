/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:00:51 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/25 05:58:01 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int dest_i;
	unsigned int src_i;

	dest_i = 0;
	src_i = 0;
	while (*(dest + dest_i) != '\0')
		dest_i++;
	while (*(src + src_i) != '\0' && src_i < nb)
	{
		*(dest + dest_i) = *(src + src_i);
		dest_i++;
		src_i++;
	}
	*(dest + dest_i) = '\0';
	return (dest);
}
