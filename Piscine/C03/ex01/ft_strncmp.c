/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:33:26 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/24 18:14:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int index;

	index = 0;
	while ((*(s1 + index) != '\0' || *(s2 + index) != '\0') && index != (int)n)
	{
		if (*(s1 + index) > *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		else if (*(s1 + index) < *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		index++;
	}
	return (0);
}
