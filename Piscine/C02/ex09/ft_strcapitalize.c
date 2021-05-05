/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:25:19 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/23 21:04:02 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*change_letter(char *str, int i, int is_first)
{
	while (*(str + i) != '\0')
	{
		if (*(str + i) > 64 && *(str + i) < 91)
		{
			if (is_first == 0)
				*(str + i) = *(str + i) + 32;
			else
				is_first = 0;
		}
		else if (*(str + i) > 96 && *(str + i) < 123)
		{
			if (is_first == 1)
			{
				*(str + i) = *(str + i) - 32;
				is_first = 0;
			}
		}
		else if (*(str + i) > 47 && *(str + i) < 58)
			is_first = 0;
		else
			is_first = 1;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int is_first;

	i = 1;
	is_first = 0;
	if (*str > 96 && *str < 123)
		*str = *str - 32;
	else if ((*str < 65 || *str > 90) && (*str < 48 || *str > 57))
		is_first = 1;
	change_letter(str, i, is_first);
	return (str);
}
