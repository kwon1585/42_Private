/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:13:46 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/09 05:05:07 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (*(s1 + index) != '\0' || *(s2 + index) != '\0')
	{
		if (*(s1 + index) != *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		index++;
	}
	return (0);
}