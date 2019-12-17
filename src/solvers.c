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
	int j0;

	while (i < tetri->col && i < (int)size)
	{
		j0 = j;
		while (j0 < tetri->row && j0 < (int)size)
		{
			if (arr[i][j0] == 1)
				return (0);
			j0++;
		}
		i++;
	}
	return (i == tetri->col ? 1 : 0);
}

static int	**add_tetri(int **arr, t_tetri *tetri, int i, int j)
{
	int j0;

	while (i < tetri->col)
	{
		j0 = j;
		while (j0 < tetri->row)
		{
			arr[i][j0] = tetri->val[i][j0];
			j0++;
		}
		i++;
	}
	return (arr);
}

static int	**remove_tetri(int **arr, t_tetri *tetri, int i, int j)
{
	int j0;

	while (i < tetri->col)
	{
		j0 = j;
		while (j0 < tetri->row)
		{
			if (tetri->val[i][j0])
				arr[i][j0] = 0;
			j0++;
		}
		i++;
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
	while (i < 0)
	{
		j = 0;
		while (j < 0)
		{
			res += eval_spot(arr, i, j, size);
			j++;
		}
		i++;
	}
	ans = (float)res/(float)size;
	printf("Eval res: %f\n", ans);
	return (ans);
}

static int	put_tetri(int **arr, size_t size, t_list *curr)
{
	int 	i;
	int 	j;
	t_tetri	*tetri;
	float	res;

	tetri = (t_tetri*)(curr->content);
	i = 0;
	res = 0.0;
	while (i < (int)size - tetri->col + 1)
	{
		j = 0;
		while (j < (int)size - tetri->row + 1)
		{
			if (can_tetri_be_placed(arr, size, tetri, i, j))
			{
				add_tetri(arr, tetri, i, j);
				print_square(arr, size);
				delay(1000);
				if (curr->next)
				{
					put_tetri(arr, size, curr->next);
					remove_tetri(arr, tetri, i, j);
				}
				else if (evaluate_square(arr, size) > res)
					res = evaluate_square(arr, size);
			}
			j++;
		}
		i++;
	}
	return (res > 0.0 ? 1 : 0);
}

int			**solve_fillit(t_list *head, size_t size)
{
	int 	**ans;
	int 	**ptr;
	int 	ret;
	int 	i;

	ft_putstr("1. solve_fillit\n");
	ans = make_square_new(size);
	while (!(ret = put_tetri(ans, size, head)))
	{
		i = 0;
		ptr = ans;
		while (i++ < (int)size)
		{
			free(*ptr);
			ptr++;
		}
		free(ans);
		size++;
		ans = make_square_new(size);
	}
	return (ans);
}