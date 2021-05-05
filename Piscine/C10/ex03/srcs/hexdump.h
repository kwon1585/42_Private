/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 03:20:00 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 03:38:29 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>

int		g_is_c;
int		g_idx;
int		g_line;
int		g_check;
int		g_star;
char	g_buff[17];
char	g_buff2[17];

int		is_option(char *str);
void	read_data(int fd);

void	print_contents_dec(unsigned char *arr);
void	print_contents_hex(unsigned char *arr);
void	print_count_hex(char *count, int last);
void	print_buff(int last);

void	print_str(char *str);
void	print_error(char *ar, char *name);

void	copy_buff(void);
int		cmp_buff(void);

#endif
