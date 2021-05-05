/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:02:05 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/17 16:05:21 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>

int		g_num;
char	*g_buf;
int		g_first_print;

void	print_str(char *str);
void	print_error(char *ar, char *name);
int		print_num_error(char *ar, char *name);
void	ft_display_file(int fd, char *str, char *name, int size);
void	stdin_mode(int fd);
int		check_size(int fd);
void	sep_files(int index, char *str);
int		ft_atoi(char *str, char *name);

#endif
