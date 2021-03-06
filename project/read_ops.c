/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 06:45:34 by esupatae          #+#    #+#             */
/*   Updated: 2019/11/14 06:45:37 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*make_tetri_new(void)
{
	t_tetri *res;
	int		i;
	int		j;

	if (!(res = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(res->val = (int**)malloc(sizeof(int*) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(res->val[i] = (int*)malloc(sizeof(int) * 4)))
			return (NULL);
		j = 0;
		while (j < 4)
		{
			res->val[i][j] = 0;
			j++;
		}
		i++;
	}
	res->col = 4;
	res->row = 4;
	return (res);
}

static t_tetri	*make_tetri_copy(t_tetri *tetri)
{
	t_tetri	*ans;
	int		i;
	int		j;

	ans = make_tetri_new();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ans->val[i][j] = tetri->val[i][j];
			j++;
		}
		i++;
	}
	return (ans);
}

static int		to_bits(char *str, int *res)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = str;
	while (i < 4)
	{
		if (*ptr == '#')
			res[i] = 1;
		else if (*ptr == '.')
			res[i] = 0;
		else
			return (0);
		ptr++;
		i++;
	}
	return (1);
}

int				get_single_tetri(int fd, t_tetri *tetri)
{
	int			count;
	int			ret;
	char		*line;
	static int	emp = -1;

	count = 0;
	while ((count + ft_abs(emp)) < 5 && (ret = get_next_line(fd, &line)))
	{
		if (is_empty_line(line) && emp >= 0)
		{
			if (count)
				return (-1);
			emp++;
		}
		else
		{
			if (ft_strlen(line) != 4 || !(to_bits(line, tetri->val[count])))
				return (-1);
			count++;
		}
		free(line);
	}
	if (!ret && !count && !emp)
		return (0);
	return (count == 4 && (emp == -1 || emp == 1) ? !(emp = 0) : -1);
}

int				get_tetris(int fd, t_list **head)
{
	int		ret;
	t_list	*curr;
	t_tetri	*tetri;

	*head = NULL;
	tetri = make_tetri_new();
	while ((ret = get_single_tetri(fd, tetri)) > 0)
	{
		if (!is_valid_tetri(tetri))
			return (-1);
		if (!(*head))
		{
			*head = ft_lstnew(make_tetri_copy(tetri), sizeof(t_tetri));
			curr = *head;
		}
		else
		{
			curr->next = ft_lstnew(make_tetri_copy(tetri), sizeof(t_tetri));
			curr = curr->next;
		}
	}
	if (!(*head))
		return (0);
	return (ret == 0 ? 1 : -1);
}
