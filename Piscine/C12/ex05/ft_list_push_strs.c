/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:51:58 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 04:24:38 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*tmp;
	t_list	*rtn;

	i = 0;
	rtn = 0;
	while (i < size)
	{
		tmp = ft_create_elem(strs[i]);
		tmp->next = rtn;
		rtn = tmp;
		i++;
	}
	return (rtn);
}
