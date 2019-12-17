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

#include "../includes/fillit.h"

static void	rem_curr(void *curr, size_t size)
{
	t_tetri	*elem;
	int 	i;

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
	size_t	size;
	int 	**ans;

	if (argc > 0)
	{
		fd = open(argv[1], O_RDONLY);
		ret = get_tetris(fd, &head);
		if (ret == -1)
			ft_putstr("error\n");
		ft_lstmap(head, &strip_tetri);
		ft_lstiter(head, &print_tetri);
		size = find_ssq(head);
		ans = solve_fillit(head, size);
		ft_lstdel(&head, &rem_curr);
		close(fd);
	}
	return (0);
}