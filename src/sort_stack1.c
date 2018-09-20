/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:57:41 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/12 17:59:41 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_mid(int *arr, int len)
{
	int		copy[len];
	int		x;
	int		y;

	x = -1;
	while (++x < len)
	{
		copy[x] = INT_MAX;
		y = -1;
		while (++y < len)
			if (arr[y] < copy[x] && (x == 0 || copy[x - 1] < arr[y]))
				copy[x] = arr[y];
	}
	return (copy[len / 2]);
}
