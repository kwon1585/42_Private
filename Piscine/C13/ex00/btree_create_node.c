/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 05:53:25 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 05:55:19 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *rtn;

	rtn = (t_btree *)malloc(sizeof(t_btree));
	rtn->left = 0;
	rtn->right = 0;
	rtn->item = item;
	return (rtn);
}
