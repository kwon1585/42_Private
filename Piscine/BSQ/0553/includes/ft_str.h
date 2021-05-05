/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:37:58 by dongkim           #+#    #+#             */
/*   Updated: 2021/03/17 23:48:31 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <unistd.h>

int		ft_strlen(char *str);
void	ft_strncpy(char *dest, char *src, int size);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
