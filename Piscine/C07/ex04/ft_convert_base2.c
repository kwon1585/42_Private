/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:15:09 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/09 04:30:56 by dokwon           ###   ########.fr       */
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

int		before_atoi_base(int *sign, char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
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

int		ft_atoi_base(char *str, char *base, int len)
{
	int sign;
	int ans;
	int dec[100];
	int i;
	int index;

	i = 0;
	sign = 1;
	index = before_atoi_base(&sign, str);
	to_dec(dec, str + index, base, len);
	ans = 0;
	while (*(dec + i) >= 0)
	{
		ans = (ans * len) + (*(dec + i) * sign);
		i++;
	}
	return (ans);
}
