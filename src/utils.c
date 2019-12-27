/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 23:01:20 by esupatae          #+#    #+#             */
/*   Updated: 2019/12/16 23:01:21 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <time.h>

void 	delay(int number_of_seconds)
{
	int milli_seconds = 1000 * number_of_seconds;

	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void 	ft_putfloat(float nb)
{
	ft_putnbr((int)nb);
	ft_putchar('.');
	ft_putnbr((int)(nb * 1000.0) % 1000);
	ft_putchar('\n');
}

void	print_square(int **sq, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i  < size)
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