/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:03:47 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:57:16 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_wp *wp, char swap)
{
	int tmp;
	int a;
	int b;

	a = wp->a[wp->a_len - 1];
	b = wp->a[wp->a_len - 2];
	if (wp->a_len <= 1)
		return ;
	tmp = a;
	a = b;
	b = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("sa\n");
		debug_print(wp);
	}
}

void	sb(t_wp *wp, char swap)
{
	int tmp;
	int a;
	int b;

	a = wp->b[wp->b_len - 1];
	b = wp->b[wp->b_len - 2];
	if (wp->b_len <= 1)
		return ;
	tmp = a;
	a = b;
	b = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("sb\n");
		debug_print(wp);
	}
}

void	ss(t_wp *wp, char swap)
{
	sa(wp, 0);
	sb(wp, 0);
	if (swap)
	{
		wp++;
		if (swap == 1)
			ft_putstr("ss\n");
		debug_print(wp);
	}
}
