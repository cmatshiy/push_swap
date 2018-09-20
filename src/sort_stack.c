/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:56:20 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:48:46 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_swap(int *arr, int len)
{
	int		i;
	int		x;

	i = len;
	x = 0;
	while (--i > 0)
	{
		if (arr[i] > arr[i - 1])
			return (x);
		x++;
	}
	return (-1);
}

int		find_max_i(int *arr, int len)
{
	int		i;
	int		max;
	int		max_i;

	i = -1;
	max = arr[0];
	max_i = 0;
	while (++i < len)
	{
		if (arr[i] > max)
		{
			max_i = i;
			max = arr[i];
		}
	}
	return (len - 1 - max_i);
}

int		find_min_i(int *arr, int len)
{
	int		i;
	int		min;
	int		min_i;

	i = -1;
	min = arr[0];
	min_i = 0;
	while (++i < len)
	{
		if (arr[i] < min)
		{
			min_i = i;
			min = arr[i];
		}
	}
	return (len - 1 - min_i);
}

int		find_max(int *arr, int len)
{
	int		i;
	int		max;

	i = -1;
	max = arr[len - 1];
	while (++i < len)
		if (arr[len - 1 - i] > max)
			max = arr[len - 1 - i];
	return (max);
}

int		find_min(int *arr, int len)
{
	int		i;
	int		min;

	i = -1;
	min = arr[len - 1];
	while (++i < len)
		if (arr[len - 1 - i] < min)
			min = arr[len - 1 - i];
	return (min);
}
