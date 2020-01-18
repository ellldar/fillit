/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 23:17:07 by esupatae          #+#    #+#             */
/*   Updated: 2019/12/09 23:17:26 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_tetri_be_placed(int **arr, size_t size, t_tetri *tetri,
		t_pos pos)
{
	int i0;
	int j0;

	i0 = pos.i;
	while (i0 - pos.i < tetri->col && i0 < (int)size)
	{
		j0 = pos.j;
		while (j0 - pos.j < tetri->row && j0 < (int)size)
		{
			if (arr[i0][j0] != 0 && tetri->val[i0 - pos.i][j0 - pos.j] != 0)
				return (0);
			j0++;
		}
		i0++;
	}
	return (i0 - pos.i == tetri->col ? 1 : 0);
}

static int	**add_tetri(int **arr, t_tetri *tetri, t_pos pos, int nb)
{
	int i0;
	int j0;

	i0 = pos.i;
	while (i0 - pos.i < tetri->col)
	{
		j0 = pos.j;
		while (j0 - pos.j < tetri->row)
		{
			if (tetri->val[i0 - pos.i][j0 - pos.j])
				arr[i0][j0] = nb;
			j0++;
		}
		i0++;
	}
	return (arr);
}

static int	**remove_tetri(int **arr, t_tetri *tetri, t_pos pos)
{
	int i0;
	int j0;

	i0 = pos.i;
	while (i0 - pos.i < tetri->col)
	{
		j0 = pos.j;
		while (j0 - pos.j < tetri->row)
		{
			if (tetri->val[i0 - pos.i][j0 - pos.j])
				arr[i0][j0] = 0;
			j0++;
		}
		i0++;
	}
	return (arr);
}

static int	put_tetri(int **arr, size_t size, t_list *curr, int nb)
{
	t_pos	pos;
	t_tetri	*tetri;

	tetri = (t_tetri*)(curr->content);
	pos.i = -1;
	while (++pos.i < (int)size - tetri->col + 1)
	{
		pos.j = -1;
		while (++pos.j < (int)size - tetri->row + 1)
		{
			if (can_tetri_be_placed(arr, size, tetri, pos))
			{
				add_tetri(arr, tetri, pos, nb);
				if (curr->next)
				{
					if (put_tetri(arr, size, curr->next, nb + 1))
						return (1);
				}
				else
					return (1);
				remove_tetri(arr, tetri, pos);
			}
		}
	}
	return (0);
}

int			**solve_fillit(t_list *head, size_t *size)
{
	int		**arr;
	int		**ptr;
	float	ret;
	int		i;

	arr = make_square_new(*size);
	while (!(ret = put_tetri(arr, *size, head, 1)))
	{
		i = 0;
		ptr = arr;
		while (i++ < (int)(*size))
		{
			free(*ptr);
			ptr++;
		}
		free(arr);
		(*size)++;
		arr = make_square_new(*size);
	}
	return (arr);
}
