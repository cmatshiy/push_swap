/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:37:41 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:22:05 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->a_len <= 1)
		return ;
	tmp = wp->a[wp->a_len - 1];
	i = wp->a_len;
	while (--i > 0)
		wp->a[i] = wp->a[i - 1];
	wp->a[0] = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("ra\n");
		debug_print(wp);
	}
}

void	rb(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->b_len <= 1)
		return ;
	tmp = wp->b[wp->b_len - 1];
	i = wp->b_len;
	while (--i > 0)
		wp->b[i] = wp->b[i - 1];
	wp->b[0] = tmp;
	if (swap)
	{
		wp->len++;
		if (swap == 1)
			ft_putstr("rb\n");
		debug_print(wp);
	}
}

void	rr(t_wp *wp, char swap)
{
	ra(wp, 0);
	rb(wp, 0);
	if (swap == 1)
	{
		wp->len++;
		ft_putstr("rr\n");
	}
	debug_print(wp);
}
