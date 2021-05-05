/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:00:00 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 04:26:42 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *now;
	t_list *to_free;

	now = begin_list;
	while (now)
	{
		to_free = now;
		now = now->next;
		free_fct(to_free->data);
		free(to_free);
	}
}
