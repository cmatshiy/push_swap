/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:04:23 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:08:50 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tsa(t_wp *wp, char swap)
{
	int	tmp;

	if (wp->ta_len <= 1)
		return ;
	tmp = wp->ta[wp->ta_len - 1];
	wp->ta[wp->ta_len - 1] = wp->ta[wp->ta_len - 2];
	wp->ta[wp->ta_len - 2] = tmp;
	if (swap)
		wp->t_len++;
}

void	tsb(t_wp *wp, char swap)
{
	int	tmp;

	if (wp->tb_len <= 1)
		return ;
	tmp = wp->tb[wp->tb_len - 1];
	wp->tb[wp->tb_len - 1] = wp->tb[wp->tb_len - 2];
	wp->tb[wp->tb_len - 2] = tmp;
	if (swap)
		wp->t_len++;
}

void	tss(t_wp *wp, char swap)
{
	(void)swap;
	tsa(wp, 0);
	tsb(wp, 0);
	wp->t_len++;
}
