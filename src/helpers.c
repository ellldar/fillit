/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 00:02:20 by esupatae          #+#    #+#             */
/*   Updated: 2019/12/12 00:02:22 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

size_t	find_ssq(t_list *head)
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

int		**make_square_new(size_t size)
{
	size_t 	i;
	int 	**res;
	int 	**ptr;

	i = 0;
	res = (int**)malloc(sizeof(int*) * size);
	if (!res)
		return (NULL);
	ptr = res;
	while (i++ < size)
	{
		*res = (int*)malloc(sizeof(int) * size);
		ft_bzero(*res++, size);
	}
	return (ptr);
}

int		**make_square_copy(int **arr, size_t size)
{
	size_t	i;
	size_t	j;
	int 	**ans;

	ans = make_square_new(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ans[i][j] = arr[i][j];
			j++;
		}
		i++;
	}
	return (ans);
}