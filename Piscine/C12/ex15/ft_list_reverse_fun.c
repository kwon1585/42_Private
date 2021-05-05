/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 05:12:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 02:54:31 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*now;
	t_list	*end;
	void	*tmp;

	end = 0;
	while (begin_list != end)
	{
		now = begin_list;
		while (now->next != end)
		{
			tmp = now->data;
			now->data = now->next->data;
			now->next->data = tmp;
			now = now->next;
		}
		end = now;
	}
}
