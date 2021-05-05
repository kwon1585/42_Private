/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 06:22:25 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 21:53:14 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *rtn;

	if (!root)
		return (0);
	else if ((rtn = btree_search_item(root->left, data_ref, cmpf)))
		return (rtn);
	else if (!cmpf(root->item, data_ref))
		return (root->item);
	else if ((rtn = btree_search_item(root->right, data_ref, cmpf)))
		return (rtn);
	else
		return (0);
}
