/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 05:00:46 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 04:26:45 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		check;
	void	*tmp;
	t_list	*now;

	if (!(*begin_list))
		return ;
	check = 1;
	while (check)
	{
		check = 0;
		now = *begin_list;
		while (now->next)
		{
			if (cmp(now->data, now->next->data) > 0)
			{
				check = 1;
				tmp = now->data;
				now->data = now->next->data;
				now->next->data = tmp;
			}
			now = now->next;
		}
	}
	return ;
}
