/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 04:56:54 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 02:48:05 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *now;

	now = *begin_list1;
	if (!now)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (now->next)
		now = now->next;
	now->next = begin_list2;
}
