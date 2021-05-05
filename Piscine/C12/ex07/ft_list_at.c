/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:23:38 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 04:29:14 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *tmp;

	tmp = begin_list;
	while (nbr--)
	{
		if (tmp == 0)
			return (0);
		tmp = tmp->next;
	}
	return (tmp);
}
