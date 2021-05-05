/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:45:43 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 17:43:10 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*one;
	t_list	*two;
	t_list	*main;
	int		start_cmp;

	if (!(*begin_list1) || !begin_list2)
	{
		*begin_list1 = (!begin_list2) ? *begin_list1 : begin_list2;
		return ;
	}
	start_cmp = cmp((*begin_list1)->data, begin_list2->data);
	one = (start_cmp > 0) ? *begin_list1 : (*begin_list1)->next;
	two = (start_cmp > 0) ? begin_list2->next : begin_list2;
	main = (start_cmp > 0) ? begin_list2 : *begin_list1;
	*begin_list1 = main;
	while (one && two)
	{
		start_cmp = cmp(one->data, two->data);
		main->next = (start_cmp > 0) ? two : one;
		one = (start_cmp > 0) ? one : one->next;
		two = (start_cmp > 0) ? two->next : two;
		main = main->next;
	}
	main->next = (one) ? one : two;
}
