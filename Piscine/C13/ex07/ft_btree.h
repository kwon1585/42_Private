/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 05:51:24 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 09:21:24 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef	struct		s_queue
{
	int				level;
	t_btree			*root;
	void			*item;
}					t_queue;

int					g_head;
int					g_tail;
int					g_level;
t_queue				*g_q;

#endif
