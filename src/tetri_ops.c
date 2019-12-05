/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:41:09 by esupatae          #+#    #+#             */
/*   Updated: 2019/12/04 21:41:11 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		print_tetri(t_list *elem)
{
	int i;
	int j;
	int	**data;

	i = 0;
	data = (int**)((t_tetri*)(elem->content))->val;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putstr(ft_itoa(data[i][j]));
			ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	ft_putchar('\n');
}

t_list		*strip_tetri(t_list	*elem)
{
	int 		i;
	int			j;
	int 		**data;
	int 		**res;
	t_coords	coords;

	i = 0;
	data = (int**)((t_tetri*)(elem->content))->val;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			j++;
		}
		i++;
	}
}