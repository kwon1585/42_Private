/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:38:05 by dongkim           #+#    #+#             */
/*   Updated: 2021/03/18 00:28:22 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdlib.h>

char	*ft_realloc(char *p, int bef_size, int size);
void	*ft_malloc(int size);
void	ft_free_all(int **map, char *p, int *saved_yx, int *arr);
char	*ft_read_file(int fd, int *filesize);

#endif
