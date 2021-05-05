/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:18:44 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/06 16:50:00 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*before_atoi(int *sign, char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int		*to_int(int *arr, char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			*(arr + i) = *(str + i) - 48;
		else
		{
			*(arr + i) = -1;
			return (arr);
		}
		i++;
	}
	*(arr + i) = -1;
	return (arr);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int ans;
	int arr[100];

	i = 0;
	ans = 0;
	sign = 1;
	str = before_atoi(&sign, str);
	to_int(arr, str);
	while (*(arr + i) >= 0)
	{
		ans = (ans * 10) + (*(arr + i) * sign);
		i++;
	}
	return (ans);
}
