/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:03:31 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:05:28 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trra(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->ta_len <= 1)
		return ;
	tmp = wp->ta[0];
	i = -1;
	while (++i < wp->ta_len - 1)
		wp->ta[i] = wp->ta[i + 1];
	wp->ta[wp->ta_len - 1] = tmp;
	if (swap)
		wp->t_len++;
}

void	trrb(t_wp *wp, char swap)
{
	int	tmp;
	int i;

	if (wp->tb_len <= 1)
		return ;
	tmp = wp->tb[0];
	i = -1;
	while (++i < wp->tb_len - 1)
		wp->tb[i] = wp->tb[i + 1];
	wp->tb[wp->tb_len - 1] = tmp;
	if (swap)
		wp->t_len++;
}

void	trrr(t_wp *wp, char swap)
{
	(void)swap;
	trra(wp, 0);
	trrb(wp, 0);
	wp->t_len++;
}
