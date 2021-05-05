/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:24:56 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/23 01:24:58 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int index;

	index = 0;
	while (*(str + index) != '\0')
	{
		if (*(str + index) >= 97 && *(str + index) <= 122)
			*(str + index) = *(str + index) - 32;
		index++;
	}
	return (str);
}
