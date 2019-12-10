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

static void	get_row_coords(int **arr, t_coords *coords)
{
	int	match;
	int	i;
	int	j;

	i = 0;
	match = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j])
			{
				if (!match)
				{
					(*coords).x0 = i;
					match = 1;
				}
				break ;
			}
			j++;
		}
		if (match && j == 4)
		{
			(*coords).x1 = i - 1;
			return ;
		}
		i++;
	}
}

static void	get_col_coords(int **arr, t_coords *coords)
{
	int	match;
	int	i;
	int	j;

	j = 0;
	match = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (arr[i][j])
			{
				if (!match)
				{
					(*coords).y0 = j;
					match = 1;
				}
				break ;
			}
			i++;
		}
		if (match && i == 4)
		{
			(*coords).y1 = j - 1;
			return ;
		}
		j++;
	}
}

void		print_tetri(t_list *elem)
{
	int i;
	int j;
	int col;
	int row;
	int	**data;

	i = 0;
	data = (int**)((t_tetri*)(elem->content))->val;
	col = (int)((t_tetri*)(elem->content))->col;
	row = (int)((t_tetri*)(elem->content))->row;
	while (i < col)
	{
		j = 0;
		while (j < row)
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
	t_coords	coords = {0, 3, 0, 3};

	data = (int**)((t_tetri*)(elem->content))->val;
	get_row_coords(data, &coords);
	get_col_coords(data, &coords);
	res = (int**)malloc(sizeof(int*) * (coords.x1 - coords.x0 + 1));
	i = 0;
	while (i < 4)
	{
		if (i >= coords.x0 && i <= coords.x1)
		{
			j = 0;
			res[i - coords.x0] = (int*)malloc(sizeof(int) * (coords.y1 - coords.y0 + 1));
			while (j < 4)
			{
				if (j >= coords.y0 && j <= coords.y1)
					res[i - coords.x0][j - coords.y0] = data[i][j];
				j++;
			}
		}
		free(data[i]);
		i++;
	}
	free(data);
	((t_tetri*)(elem->content))->val = res;
	((t_tetri*)(elem->content))->col = coords.x1 - coords.x0 + 1;
	((t_tetri*)(elem->content))->row = coords.y1 - coords.y0 + 1;
	return(elem);
}