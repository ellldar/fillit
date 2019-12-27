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

size_t	*find_ssq(t_list *head)
{
	t_list	*ptr;
	int		count;
	int		i;
	size_t	*ans;

	ans = (size_t*)malloc(sizeof(size_t));
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
	*ans = (size_t)i;
	return (ans);
}

int		**make_square_new(size_t size)
{
	size_t	i;
	size_t	j;
	int		**res;
	int		**ptr;

	i = 0;
	res = (int**)malloc(sizeof(int*) * size);
	if (!res)
		return (NULL);
	ptr = res;
	while (i++ < size)
	{
		*res = (int*)malloc(sizeof(int) * size);
		j = 0;
		while (j++ < size)
			(*res)[j - 1] = 0;
		res++;
	}
	return (ptr);
}

int		is_empty_line(char *str)
{
	while (*str)
	{
		if (*str != ' ' || *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

void	print_square(int **sq, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(sq[i][j] ? (sq[i][j] + 'A' - 1) : '.');
			ft_putstr(j != size - 1 ? " " : "");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
