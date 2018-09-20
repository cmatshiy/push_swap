/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:01:31 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:59:52 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tpa(t_wp *wp, char swap)
{
	if (wp->tb_len == 0)
		return ;
	wp->ta[wp->ta_len] = wp->tb[wp->tb_len - 1];
	wp->tb[wp->tb_len - 1] = 0;
	wp->ta_len++;
	wp->tb_len--;
	if (swap)
		wp->t_len++;
}

void	tpb(t_wp *wp, char swap)
{
	if (wp->ta_len == 0)
		return ;
	wp->tb[wp->tb_len] = wp->ta[wp->ta_len - 1];
	wp->ta[wp->ta_len - 1] = 0;
	wp->tb_len++;
	wp->ta_len--;
	if (swap)
		wp->t_len++;
}
