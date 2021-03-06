/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:32:08 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/17 22:32:11 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

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

typedef struct	s_pos
{
	int			i;
	int			j;
}				t_pos;

int				get_tetris(int fd, t_list **head);
int				get_single_tetri(int fd, t_tetri *tetri);
t_list			*strip_tetri(t_list	*elem);
size_t			*find_ssq(t_list *head);
int				**make_square_new(size_t size);
int				is_valid_tetri(t_tetri *tetri);
int				is_empty_line(char *str);
int				**solve_fillit(t_list *head, size_t *size);

void			print_square(int **sq, size_t size);

#endif
