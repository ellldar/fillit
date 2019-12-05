/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:43:11 by esupatae          #+#    #+#             */
/*   Updated: 2019/11/23 20:43:14 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

typedef struct	s_tetri	t_tetri;

typedef struct	s_tetri
{
	int			**val;
	int			x;
	int			y;
}				t_tetri;

int				get_tetris(int fd, t_list **head);
int				get_single_tetri(int fd, t_tetri *tetri);

#endif