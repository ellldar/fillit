/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:44:30 by esupatae          #+#    #+#             */
/*   Updated: 2019/10/23 02:44:33 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_skip_char(char **ptr, char c)
{
	char *s;

	if (!ptr || !*ptr)
		return (0);
	s = *ptr;
	while (*s == c)
		s++;
	*ptr = s;
	return (*s != '\0' ? 1 : 0);
}