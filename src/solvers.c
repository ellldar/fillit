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
#include <stdio.h>

static int	can_tetri_be_placed(int **arr, size_t size, t_tetri *tetri, int i, int j)
{
	int i0;
	int j0;

	i0 = i;
	while (i0 - i < tetri->col && i0 < (int)size)
	{
		j0 = j;
		while (j0 - j < tetri->row && j0 < (int)size)
		{
			if (arr[i0][j0] != 0)
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
			arr[i0][j0] = tetri->val[i0 - i][j0 - j] ? nb : 0;
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

static float	evaluate_square(int **arr, size_t size)
{
	int		i;
	int		j;
	int		res;
	float	ans;

	i = 0;
	res = 0;
	if (!arr)
		return (0);
	while (i < (int)size)
	{
		j = 0;
		while (j < (int)size)
		{
			res += eval_spot(arr, i, j, size);
			j++;
		}
		i++;
	}
	ans = (float)res/(float)size;
	return (ans);
}

static int	put_tetri(int **arr, size_t size, t_list *curr, int ***ans, int nb)
{
	int 	i;
	int 	j;
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
					put_tetri(arr, size, curr->next, ans, nb + 1);
				else if (evaluate_square(arr, size) > evaluate_square(*ans, size))
				{
					if (!*ans)
						*ans = make_square_new(size);
					make_square_copy(*ans, arr, size);
				}
				remove_tetri(arr, tetri, i, j);
			}
			j++;
		}
		i++;
	}
	return (*ans ? 1 : 0);
}

int		**solve_fillit(t_list *head, size_t *size)
{
	int 		***ans;
	int 		**arr;
	int 		**ptr;
	float 		ret;
	int 		i;

	arr = make_square_new(*size);
	ans = (int***)malloc(sizeof(int**));
	while (!(ret = put_tetri(arr, *size, head, ans, 1)))
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
		ft_putstr("Size: ");
		ft_putnbr((int)(*size));
		ft_putstr("\n");
		arr = make_square_new(*size);
	}
	return (*ans);
}