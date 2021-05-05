/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:58:18 by seehan            #+#    #+#             */
/*   Updated: 2021/02/20 11:31:41 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int now_x;
	int now_y;

	now_y = 1;
	while (now_y <= y)
	{
		now_x = 1;
		while (now_x <= x)
		{
			if ((now_x == 1 && now_y == 1) || (now_x == x && now_y == y))
				ft_putchar('o');
			else if ((now_x == 1 && now_y == y) || (now_x == x && now_y == 1))
				ft_putchar('o');
			else if (now_x == 1 || now_x == x)
				ft_putchar('|');
			else if (now_y == 1 || now_y == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			now_x++;
		}
		ft_putchar('\n');
		now_y++;
	}
}
