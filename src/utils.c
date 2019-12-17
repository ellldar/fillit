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

void	print_square(int **sq, size_t size)
{
	int i;
	int j;

	i = 0;
	while (i  < (int)size)
	{
		j = 0;
		while (j < (int)size)
		{
			ft_putnbr(sq[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}