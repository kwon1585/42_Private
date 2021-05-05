/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:40:24 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 04:26:27 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	free_list(void (*free_fct)(void *))
{
	free_fct(g_now->data);
	free(g_now);
}

void	next_list(void)
{
	g_prev = g_now;
	g_now = g_now->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	g_now = *begin_list;
	while (g_now && (cmp(g_now->data, data_ref) == 0))
	{
		*begin_list = g_now->next;
		free_list(free_fct);
		g_now = *begin_list;
	}
	if (!g_now || !g_now->next)
		return ;
	next_list();
	while (g_now)
		if (cmp(g_now->data, data_ref) == 0)
		{
			g_tmp = g_now->next;
			free_list(free_fct);
			g_prev->next = g_tmp;
			g_now = g_tmp;
		}
		else
			next_list();
}
