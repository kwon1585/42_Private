/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:18:42 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 21:07:01 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

struct s_point	make_next_struct(struct s_point p)
{
	struct s_point p_tmp;

	if (p.col == 3)
	{
		p_tmp.row = p.row + 1;
		p_tmp.col = 0;
	}
	else
	{
		p_tmp.row = p.row;
		p_tmp.col = p.col + 1;
	}
	return (p_tmp);
}
