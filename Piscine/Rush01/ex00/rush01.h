/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:33:54 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/07 21:07:19 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

struct			s_point
{
	int			row;
	int			col;
};
void			rush_init(int **ans, int *side);
void			print_ans(int **ans);
int				input_error(int *side, char *num);
int				check_row(int **ans, int *side, struct s_point p);
int				check_col(int **ans, int *side, struct s_point p);
int				finish_row(int **ans, int *side, struct s_point p);
int				finish_col(int **ans, int *side, struct s_point p);
struct s_point	make_next_struct(struct s_point p);
int				put_data(int **ans, int *side, struct s_point p, int num);
#endif
