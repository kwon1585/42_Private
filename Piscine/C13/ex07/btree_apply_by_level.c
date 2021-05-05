/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 06:40:25 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 09:23:47 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	init_global(void)
{
	g_head = 0;
	g_tail = 0;
	g_level = -1;
}

int		count_node(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + count_node(root->left) + count_node(root->right));
}

void	in_queue(t_btree *root, int level)
{
	if (!root)
		return ;
	g_q[g_tail].level = level;
	g_q[g_tail].root = root;
	g_q[g_tail].item = root->item;
	g_tail++;
}

void	en_queue(void (*applyf)(void *item, int current_level, int is_first))
{
	int lv;

	lv = g_q[g_head].level;
	in_queue(g_q[g_head].root->left, lv + 1);
	in_queue(g_q[g_head].root->right, lv + 1);
	if (g_level < lv)
	{
		applyf(g_q[g_head].item, lv, 1);
		g_level = lv;
	}
	else
		applyf(g_q[g_head].item, lv, 0);
	g_head++;
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;

	init_global();
	count = count_node(root);
	g_q = (t_queue *)malloc(sizeof(t_queue) * (count + 1));
	in_queue(root, 0);
	while (g_head != g_tail)
		en_queue(applyf);
}
