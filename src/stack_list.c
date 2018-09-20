/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:52:25 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:29:13 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_swaps(t_wp *wp)
{
	int		nb_swaps;
	int		i;

	nb_swaps = 0;
	i = -1;
	while (++i < wp->a_len - 2)
		if (wp->a[i] < wp->a[i + 1])
			nb_swaps++;
	return (nb_swaps);
}

int		check_rotates(t_wp *wp)
{
	int		i;
	int		last;

	i = wp->a_len;
	last = 0;
	while (--i >= 0)
	{
		if (wp->a[i] > wp->a[i - 1])
		{
			i--;
			break ;
		}
		last++;
	}
	while (i != wp->a_len - 1 - last)
	{
		if (wp->a[i] > wp->a[i - 1] ||
			(i == 0 && wp->a[0] >= wp->a[wp->a_len - 1]))
			return (0);
		i--;
		if (i < 0)
			i = wp->a_len;
	}
	return (wp->a[i] <= wp->a[wp->a_len - 1] ? last + 1 : 0);
}

int		is_stack_sort(int *arr, int len, char rev)
{
	int i;

	i = -1;
	while (++i < len - 1)
		if ((arr[i] < arr[i + 1]) ^ rev)
			return (0);
	return (1);
}

int		is_sort(t_wp *wp)
{
	int i;

	if (wp->b_len)
		return (0);
	i = -1;
	while (++i < wp->a_len - 1)
		if (wp->a[i] < wp->a[i + 1])
			return (0);
	return (1);
}

int		find_pos(int *arr, int len, int val)
{
	int x;

	x = -1;
	while (++x < len)
	{
		if (val < arr[len - 1] && val > arr[0])
			return (x);
		else if (val < arr[len - 1] && arr[0] == find_max(arr, len))
			return (x);
		else if (val > arr[0] && arr[len - 1] == find_min(arr, len))
			return (x);
	}
	return (-1);
}
