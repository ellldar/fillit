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

	i = -1;
	match = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
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
		}
		if (match && j == 4)
			return ((void)((*coords).x1 = i - 1));
	}
}

static void	get_col_coords(int **arr, t_coords *coords)
{
	int	match;
	int	i;
	int	j;

	j = -1;
	match = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
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
		}
		if (match && i == 4)
			return ((void)((*coords).y1 = j - 1));
	}
}

static void	get_tetri_data(int **res, int **data, t_coords coords)
{
	int	i;
	int	j;

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
}

t_list		*strip_tetri(t_list *elem)
{
	int			**data;
	int			**res;
	t_coords	coords = {0, 3, 0, 3};

	data = (int**)((t_tetri*)(elem->content))->val;
	if (!data)
		return (NULL);
	get_row_coords(data, &coords);
	get_col_coords(data, &coords);
	res = (int**)malloc(sizeof(int*) * (coords.x1 - coords.x0 + 1));
	if (!res)
		return (NULL);
	get_tetri_data(res, data, coords);
	((t_tetri*)(elem->content))->val = res;
	((t_tetri*)(elem->content))->col = coords.x1 - coords.x0 + 1;
	((t_tetri*)(elem->content))->row = coords.y1 - coords.y0 + 1;
	return (elem);
}
