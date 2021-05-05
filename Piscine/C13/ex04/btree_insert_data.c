/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 06:09:35 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/18 00:17:00 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!(*root))
		(*root) = btree_create_node(item);
	else if (cmpf((*root)->item, item) > 0)
	{
		if (!((*root)->left))
			(*root)->left = btree_create_node(item);
		else
			btree_insert_data(&((*root)->left), item, cmpf);
	}
	else
	{
		if (!((*root)->right))
			(*root)->right = btree_create_node(item);
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
}
