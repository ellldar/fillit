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

#include "../includes/fillit.h"

static int	can_tetri_be_placed(int **arr, size_t size, t_tetri *tetri,
		int i, int j)
{
	int i0;
	int j0;

	i0 = i;
	while (i0 - i < tetri->col && i0 < (int)size)
	{
		j0 = j;
		while (j0 - j < tetri->row && j0 < (int)size)
		{
			if (arr[i0][j0] != 0 && tetri->val[i0 - i][j0 - j] != 0)
				return (0);
			j0++;
		}
		i0++;
	}
	return (i0 - i == tetri->col ? 1 : 0);
}

static int	**add_tetri(int **arr, t_tetri *tetri, int i, int j, int nb)
{
	int i0;
	int j0;

	i0 = i;
	while (i0 - i < tetri->col)
	{
		j0 = j;
		while (j0 - j < tetri->row)
		{
			if (tetri->val[i0 - i][j0 - j])
				arr[i0][j0] = nb;
			j0++;
		}
		i0++;
	}
	return (arr);
}

static int	**remove_tetri(int **arr, t_tetri *tetri, int i, int j)
{
	int i0;
	int j0;

	i0 = i;
	while (i0 - i < tetri->col)
	{
		j0 = j;
		while (j0 - j < tetri->row)
		{
			if (tetri->val[i0 - i][j0 - j])
				arr[i0][j0] = 0;
			j0++;
		}
		i0++;
	}
	return (arr);
}

static int	put_tetri(int **arr, size_t size, t_list *curr, int nb)
{
	int		i;
	int		j;
	t_tetri	*tetri;

	tetri = (t_tetri*)(curr->content);
	i = 0;
	while (i < (int)size - tetri->col + 1)
	{
		j = 0;
		while (j < (int)size - tetri->row + 1)
		{
			if (can_tetri_be_placed(arr, size, tetri, i, j))
			{
				add_tetri(arr, tetri, i, j, nb);
				if (curr->next)
				{
					if (put_tetri(arr, size, curr->next, nb + 1))
						return (1);
				}
				else
					return (1);
				remove_tetri(arr, tetri, i, j);
			}
			j++;
		}
		i++;
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
