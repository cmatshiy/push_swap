/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:41:35 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:45:00 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->a_len <= 1)
		return ;
	tmp = wp->a[0];
	i = -1;
	while (++i < wp->a_len - 1)
		wp->a[i] = wp->a[i + 1];
	wp->a[wp->a_len - 1] = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("rra\n");
		debug_print(wp);
	}
}

void	rrb(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->b_len <= 1)
		return ;
	tmp = wp->b[0];
	i = -1;
	while (++i < wp->b_len - 1)
		wp->b[i] = wp->b[i + 1];
	wp->b[wp->b_len - 1] = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("rrb\n");
		debug_print(wp);
	}
}

void	rrr(t_wp *wp, char swap)
{
	rra(wp, 0);
	rrb(wp, 0);
	if (swap == 1)
	{
		wp->len++;
		ft_putstr("rrr\n");
	}
	debug_print(wp);
}
