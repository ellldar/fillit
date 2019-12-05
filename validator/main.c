/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:23:10 by esupatae          #+#    #+#             */
/*   Updated: 2019/11/08 22:25:45 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "header.h"

void	calc_array(int **arr, size_t size)
{
	int 		i;
	int 		j;
	int			i0;
	int			j0;
	int			s;
	int			st_size;
	static int	steps[] = {0, -1, -1, 0, 0, 1, 1, 0};
	int 		n;
	int 		sum;
	float		res;

	n = 0;
	i = 0;
	sum = 0;
	st_size = 8;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			n = 0;
			s = 0;
			while (s < st_size)
			{
				i0 = i + steps[s];
				j0 = j + steps[s + 1];
				if (i0 >= 0 && i0 < size && j0 >= 0 && j0 < size && arr[i][j] != 0)
					n += arr[i0][j0];
				s += 2;
			}
			sum += n;
			printf("%i ", n);
			j++;
		}
		printf("\n");
		free(arr[i]);
		i++;
	}
	res = (float)sum / size;
	printf("The sum   : %i\n", sum);
	printf("The grade : %f\n", res);
	free(arr);
}

void	print_array(int **arr, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%i ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	int 	**arr;
	size_t 	size;
	int		fd;

	size = 0;
	if (argc > 1 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		while (get_next_array(fd, &arr, &size))
		{
			print_array(arr, size);
			printf("\n");
			calc_array(arr, size);
			printf("\n");
		}
		close(fd);
	}
	return (0);
}