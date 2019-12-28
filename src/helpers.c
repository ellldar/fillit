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

int		is_valid_tetri(t_tetri *tetri)
{
	int			count;
	int			i;
	int			j;
	int			s;
	static int	st[8] = {0, -1, -1, 0, 0, 1, 1, 0};

	count = 0;
	i = -1;
	while (++i < tetri->col)
	{
		j = -1;
		while (++j < tetri->row)
		{
			if (tetri->val[i][j])
			{
				count++;
				s = -2;
				while ((s += 2) < 8)
					if (i + st[s] >= 0 && i + st[s] < tetri->col &&
						j + st[s + 1] >= 0 && j + st[s + 1] < tetri->row)
						count += tetri->val[i + st[s]][j + st[s + 1]];
			}
		}
	}
	return (count == 10 || count == 12);
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
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
