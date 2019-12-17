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

int		eval_spot(int **arr, int i, int j, size_t size)
{
	int			ans;
	int 		s;
	static int	steps[] = {0, -1, -1, 0, 0, 1, 1, 0};

	s = 0;
	ans = 0;
	while (s < 8)
	{
		if (i + steps[s] >= 0 && i + steps[s] <= (int)size &&
			j + steps[s + 1] >= 0 && i + steps[s + 1] <= (int)size)
			ans += arr[i + steps[s]][j + steps[s + 1]];
		s += 2;
	}
	return (ans);
}