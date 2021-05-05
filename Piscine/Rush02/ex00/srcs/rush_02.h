/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:40:49 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/14 22:20:49 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		g_argc;
char	*g_dict;
int		g_idx;
char	g_ans[1000];

void	push(char c);
void	print_ans(void);
int		check_num_three(char *str);
int		check_num(char *str, int size);
int		ft_strlen(char *str);
char	*ft_strsplit(char *str, int size, int pos);
int		ft_strstr(char *src, char *str);
void	ft_printdict(char *buff);
void	ft_changestr(char *str, int fd);
void	ft_ctos(char c);
void	ft_numbers(char *str, int len, char *c);
int		print_error(int n);
int		print_unit(int fd, int len, int size);
void	print_three(char *num, int fd);
int		print_num(int fd, char *num, char *num_three, int len);
char	*get_num(char *str, int *len);
char	*get_line(int fd);
char	*make_three(char *str, int len);
int		re_open(int fd);

#endif
