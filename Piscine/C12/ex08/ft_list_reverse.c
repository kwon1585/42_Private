/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:12:08 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 04:34:57 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *now;
	t_list *tmp;
	t_list *prev;

	now = *begin_list;
	if (now == 0 || now->next == 0)
		return ;
	prev = 0;
	while (now)
	{
		tmp = now->next;
		now->next = prev;
		prev = now;
		now = tmp;
	}
	*begin_list = prev;
	return ;
}
