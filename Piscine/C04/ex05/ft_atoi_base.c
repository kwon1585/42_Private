/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:16:51 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 06:14:54 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_atoi_base(char *base)
{
	int i;
	int j;
	int rtn;

	i = 0;
	rtn = 0;
	while (*(base + i) != '\0')
	{
		j = i + 1;
		while (*(base + j) != '\0')
		{
			if (*(base + i) == *(base + j))
				return (-1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-' || *(base + i) == ' ' ||
			*(base + i) == '\n' || *(base + i) == '\t' || *(base + i) == '\r' ||
			*(base + i) == '\v' || *(base + i) == '\f')
			return (-1);
		i++;
		rtn++;
	}
	return (rtn);
}

char	*before_atoi_base(int *sign, char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int		*to_dec(int *dec, char *str, char *base, int len)
{
	int i;
	int j;
	int check;

	i = 0;
	while (*(str + i) != '\0')
	{
		j = -1;
		check = 0;
		while (++j < len)
			if (*(str + i) == *(base + j))
			{
				*(dec + i) = j;
				check = 1;
				break ;
			}
		if (check == 0)
		{
			*(dec + i) = -1;
			return (dec);
		}
		i++;
	}
	*(dec + i) = -1;
	return (dec);
}

int		ft_atoi_base(char *str, char *base)
{
	int len;
	int sign;
	int ans;
	int dec[100];
	int i;

	i = 0;
	len = check_atoi_base(base);
	if (len <= 1)
		return (0);
	sign = 1;
	str = before_atoi_base(&sign, str);
	to_dec(dec, str, base, len);
	ans = 0;
	while (*(dec + i) >= 0)
	{
		ans = (ans * len) + (*(dec + i) * sign);
		i++;
	}
	return (ans);
}
