/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:35:40 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 04:18:06 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;
	t_list *last;

	last = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = last;
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
}
