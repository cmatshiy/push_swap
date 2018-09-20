/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:09:58 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/06/08 14:14:54 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char start;

	if (s)
	{
		start = '\n';
		while (*s != 0)
		{
			write(1, s, 1);
			s++;
		}
		write(1, &start, 1);
	}
}