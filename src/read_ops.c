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

#include "../includes/fillit.h"

static int	*to_bits(char *str)
{
	int *res;
	int *ptr;
	int i;

	if (!(res = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	ptr = res;
	i = 0;
	while (i < 4)
	{
		if (*str == '#')
			*res = 1;
		else if (*str == '.')
			*res = 0;
		else
			return (NULL);
		str++;
		res++;
		i++;
	}
	return (ptr);
}

int			get_single_tetri(int fd, t_tetri *tetri)
{
	int		count;
	int 	ret;
	int 	**ans;
	char 	*line;

	count = 0;
	if (!(tetri->val = (int**)malloc(sizeof(int*) * 4)))
		return (-1);
	tetri->col = 4;
	tetri->row = 4;
	ans = tetri->val;
	while ((ret = get_next_line(fd, &line)))
	{
		if (count < 4)
		{
			if (ft_strlen(line) != 4 || !(*ans = to_bits(line)))
				return (-1);
			ans++;
			count++;
		}
		else
			return (1);
		free(line);
	}
	return (count == 4 ? 1 : 0);
}

int			get_tetris(int fd, t_list **head)
{
	int		ret;
	t_list	*curr;
	t_tetri	tetri;

	if (!(*head = (t_list*)malloc(sizeof(t_tetri))))
		return (-1);
	while ((ret = get_single_tetri(fd, &tetri)) > 0)
	{
		if (!(*head)->content)
		{
			*head = ft_lstnew(&tetri, sizeof(t_tetri));
			curr = *head;
		}
		else
		{
			curr->next = ft_lstnew(&tetri, sizeof(t_tetri));
			curr = curr->next;
		}
	}
	return (ret == 0 ? 1 : -1);
}