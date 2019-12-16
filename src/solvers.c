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
	while (i < tetri->col && i < (int)size)
	{
		while (j < tetri->row && j < (int)size)
		{
			if (arr[i][j] == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (i == tetri->col && j == tetri->row ? 1 : 0);
}

static int	**add_tetri(int **arr, t_tetri *tetri, int i, int j)
{
	while (i < tetri->col)
	{
		while (j < tetri->row)
		{
			arr[i][j] = tetri->val[i][j];
			j++;
		}
		i++;
	}
	return (arr);
}

static int	**remove_tetri(int **arr, t_tetri *tetri, int i, int j)
{
	while (i < tetri->col)
	{
		while (j < tetri->row)
		{
			if (tetri->val[i][j])
				arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

static int	evaluate_square(int **arr)
{
	int **tmp;

	tmp = arr;
	return (1);
}

static int	put_tetri(int **arr, size_t size, t_list *head)
{
	int 	i;
	int 	j;
	t_list	*curr;
	t_tetri	*tetri;
	int		res;

	curr = head;
	tetri = (t_tetri*)(curr->content);
	i = 0;
	while (i < (int)size - tetri->col + 1)
	{
		j = 0;
		while (j < (int)size - tetri->row + 1)
		{
			if (!(curr->next))
			{
				if (evaluate_square(add_tetri(arr, tetri, i, j)) > res)
					res = evaluate_square(add_tetri(arr, tetri, i, j));
			}
			else if (can_tetri_be_placed(arr, size, tetri, i, j))
			{
				put_tetri(add_tetri(arr, tetri, i, j), size, curr->next);
				remove_tetri(arr, tetri, i, j);
			}
			j++;
		}
		i++;
	}
	return (res > 0 ? 1 : 0);
}

int			**solve_fillit(t_list *head, size_t size)
{
	int 	**ans;
	int 	**ptr;
	int 	ret;
	int 	i;

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