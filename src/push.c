/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:45:44 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:10:35 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_wp *wp, char swap)
{
	if (wp->b_len == 0)
		return ;
	wp->a[wp->a_len] = wp->b[wp->b_len - 1];
	wp->b[wp->b_len - 1] = 0;
	wp->a_len++;
	wp->b_len--;
	if (swap == 1)
	{
		wp->len++;
		ft_putstr("pa\n");
	}
	debug_print(wp);
}

void	pb(t_wp *wp, char swap)
{
	if (wp->a_len == 0)
		return ;
	wp->b[wp->b_len] = wp->a[wp->a_len - 1];
	wp->a[wp->a_len - 1] = 0;
	wp->b_len++;
	wp->a_len--;
	if (swap == 1)
	{
		wp->len++;
		ft_putstr("pb\n");
	}
	debug_print(wp);
}
