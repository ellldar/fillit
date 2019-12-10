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

size_t		find_ssq(t_list *head)
{
	t_list	*ptr;
	int 	count;
	int 	i;

	i = 0;
	count = 0;
	ptr = head;
	while (ptr)
	{
		count += 4;
		ptr = ptr->next;
	}
	while (i * i < count)
		i++;
	return (i);
}

static char	**make_empty_square(size_t size)
{
	size_t 	i;
	char 	**res;
	char 	**ptr;

	i = 0;
	res = (char**)malloc(sizeof(char*) * (size + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (i++ < size)
	{
		*res = (char*)malloc(sizeof(char) * (size + 1));
		ft_bzero(*res++, size + 1);
	}
	return (ptr);
}

int			try_pieces(char **arr, size_t size, t_list *head)
{
	int 	i;
	int 	j;
	t_list	*curr;
	t_tetri	*tetri;

	curr = head;
	tetri = (t_tetri*)(curr->content);
	i = 0;
	while (i < (int)size - tetri->col + 1)
	{
		j = 0;
		while (j < (int)size - tetri->row + 1)
		{
			if (curr->next && tetri_can_be_placed(arr, tetri, i, j))
				try_pieces(add_tetri_to_square(arr, tetri, i, j), size, curr->next);
			else
				evaluate_square(add_tetri_to_square(arr, tetri, i, j));
		}
	}
}

char		**solve_fillit(t_list *head, size_t size)
{
	char 	**ans;
	char 	**ptr;
	int 	ret;
	int 	i;

	ans = make_empty_square(size);
	while (!(ret = try_pieces(ans, size, head)))
	{
		i = 0;
		ptr = ans;
		while (i++ < size)
		{
			free(*ptr);
			ptr++;
		}
		free(ans);
		ans = make_empty_square(size + 1);
	}
	return (ans);
}