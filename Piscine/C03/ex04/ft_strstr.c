/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:13:56 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/11 00:58:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_compare(char *str, char *to_find)
{
	int i;

	i = 0;
	while (*(to_find + i) != '\0')
	{
		if (*(str + i) != *(to_find + i))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int str_i;
	int to_find_i;

	str_i = 0;
	to_find_i = 0;
	if (*to_find == '\0')
		return (str);
	while (*(str + str_i) != '\0')
	{
		if (*(str + str_i) == *to_find)
		{
			if (str_compare(str + str_i, to_find) == 1)
				str_i++;
			else
				return (str + str_i);
		}
		else
			str_i++;
	}
	return (0);
}
