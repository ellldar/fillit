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

#include "../libft/libft.h"
#include "header.h"
#include <stdio.h>

static int		**make_array(size_t size)
{
	int	**ans;

	ans = (int**)malloc(sizeof(int*) * size);
	return (ans);
}

static int		*to_bits(int n, size_t size)
{
	int		*ans;
	int 	*ptr;
	int 	i;

	i = (int)size;
	ans = (int*)malloc(sizeof(int) * size);
	ptr = ans;
	ft_bzero(ans, sizeof(int) * size);
	while (i-- > 0)
		*ptr++ = (n & (1 << i)) ? 1 : 0;
	return (ans);
}

int				get_next_array(const int fd, int ***arr, size_t *size)
{
	int			**ans;
	int			res;
	char		*line;
	static int	isbeg = 1;
	int			ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strlen(line) < 2 && ret)
			return(isbeg = 1);
		if (isbeg)
		{
			isbeg = 0;
			*size = ft_strlen(line);
			*arr = make_array(*size);
			ans = *arr;
		}
		res = ft_atoi_base(line, 2);
		*ans++ = to_bits(res, *size);
		free(line);
	}
	if (!isbeg && ft_strlen(line) > 1)
		return (isbeg = 1);
	return (0);
}