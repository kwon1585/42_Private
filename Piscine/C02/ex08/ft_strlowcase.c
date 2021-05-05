/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:25:08 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/23 01:25:09 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int index;

	index = 0;
	while (*(str + index) != '\0')
	{
		if (*(str + index) >= 65 && *(str + index) <= 90)
			*(str + index) = *(str + index) + 32;
		index++;
	}
	return (str);
}
