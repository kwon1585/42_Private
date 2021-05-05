/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 01:45:37 by dokwon            #+#    #+#             */
/*   Updated: 2021/03/13 21:22:24 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	i = 1;
	while (tab[i])
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
		{
			ft_swap(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
}
