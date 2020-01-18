/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:31:29 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/17 22:31:35 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	rem_curr(void *curr, size_t size)
{
	t_tetri	*elem;
	int		i;

	i = 0;
	elem = (t_tetri*)curr;
	while (i < elem->col)
		free(elem->val[i++]);
	free(elem->val);
	ft_memset(elem, 0, size);
	free(elem);
	elem = NULL;
}

int			main(int argc, char **argv)
{
	int		ret;
	int		fd;
	t_list	*head;
	size_t	*size;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) <= 0 ||
			(ret = get_tetris(fd, &head)) <= 0)
			ft_putstr("error\n");
		else
		{
			ft_lstmap(head, &strip_tetri);
			size = find_ssq(head);
			print_square(solve_fillit(head, size), *size);
			ft_lstdel(&head, &rem_curr);
			close(fd);
		}
	}
	else
		ft_putstr("usage: ./fillit [source_file]\n");
	return (0);
}
