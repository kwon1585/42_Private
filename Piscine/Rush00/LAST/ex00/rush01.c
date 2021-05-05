/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeong <jjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:56:37 by jjeong            #+#    #+#             */
/*   Updated: 2021/02/20 13:50:15 by jjeong           ###   ########.fr       */
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
			if (now_x == 1 && now_y == 1)
				ft_putchar('/');
			else if (now_x != 1 && now_y != 1 && now_x == x && now_y == y)
				ft_putchar('/');
			else if ((now_x == 1 && now_y == y) || (now_y == 1 && now_x == x))
				ft_putchar('\\');
			else if (now_x == 1 || now_x == x || now_y == 1 || now_y == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			now_x++;
		}
		ft_putchar('\n');
		now_y++;
	}
}
