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

#include "../libft/libft.h"

typedef struct	s_tetri
{
	int			**val;
	int			col;
	int			row;
}				t_tetri;

typedef struct	s_coords
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_coords;

int				get_tetris(int fd, t_list **head);
int				get_single_tetri(int fd, t_tetri *tetri);
void			print_tetri(t_list *elem);
t_list			*strip_tetri(t_list	*elem);

#endif