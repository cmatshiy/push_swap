/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:02:21 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:02:31 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tra(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->ta_len <= 1)
		return ;
	tmp = wp->ta[wp->ta_len - 1];
	i = wp->ta_len;
	while (--i > 0)
		wp->ta[i] = wp->ta[i - 1];
	wp->ta[0] = tmp;
	if (swap)
		wp->t_len++;
}

void	trb(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->tb_len <= 1)
		return ;
	tmp = wp->tb[wp->tb_len - 1];
	i = wp->tb_len;
	while (--i > 0)
		wp->tb[i] = wp->tb[i - 1];
	wp->tb[0] = tmp;
	if (swap)
		wp->t_len++;
}

void	trr(t_wp *wp, char swap)
{
	(void)swap;
	tra(wp, 0);
	trb(wp, 0);
	wp->t_len++;
}
