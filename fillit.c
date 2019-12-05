/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:29:48 by esupatae          #+#    #+#             */
/*   Updated: 2019/11/08 22:29:52 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		rem_curr(void *curr, size_t size)
{
	t_tetri	*elem;
	int 	i;

	i = 0;
	elem = (t_tetri*)curr;
	while (i < elem->x)
		free(elem->val[i++]);
	free(elem->val);
	ft_memset(elem, 0, size);
	free(elem);
	elem = NULL;
}

int	main(int argc, char **argv)
{
	int		ret;
	int		fd;
	t_list	*head;
	t_list	*curr;
	int 	i, j;
	int 	**data;

	if (argc > 0)
	{
		fd = open(argv[1], O_RDONLY);
		ret = get_tetris(fd, &head);
		if (ret == -1)
			ft_putstr("error\n");
		while (head)
		{
			i = 0;
			data = (int**)((t_tetri*)(head->content))->val;
			while (i < 4)
			{
				j = 0;
				while (j < 4)
				{
					ft_putstr(ft_itoa(data[i][j]));
					ft_putchar(' ');
					j++;
				}
				ft_putstr("\n");
				i++;
			}
			ft_putchar('\n');
			curr = head;
			head = head->next;
			ft_lstdelone(&curr, &rem_curr);
		}
		close(fd);
	}
	return (0);
}
