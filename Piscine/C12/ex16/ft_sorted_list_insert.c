/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:50:08 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 04:25:41 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*now;
	t_list	*prev;
	t_list	*tmp;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if (cmp((*begin_list)->data, data) > 0)
	{
		tmp = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = tmp;
		return ;
	}
	prev = *begin_list;
	now = prev->next;
	while (now && cmp(now->data, data) < 0)
	{
		prev = now;
		now = now->next;
	}
	prev->next = ft_create_elem(data);
	prev->next->next = now;
}
