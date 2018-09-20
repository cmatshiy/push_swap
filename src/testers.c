/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:59:48 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:32:11 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_only_swaps(t_wp *wp)
{
	int		i_swap;
	int		cpt;
	int		tmp;

	i_swap = 0;
	while (i_swap != -1)
	{
		i_swap = get_swap(wp->ta, wp->ta_len);
		cpt = i_swap;
		while (cpt <= wp->ta_len / 2 ? cpt-- > 0 : cpt++ < wp->ta_len)
			i_swap <= wp->ta_len / 2 ? tra(wp, 1) : trra(wp, 1);
		if (wp->ta[wp->ta_len - 1] > wp->ta[wp->ta_len - 2])
			tsa(wp, 1);
		cpt = i_swap;
		while (cpt <= wp->ta_len / 2 ? cpt-- > 0 : cpt++ < wp->ta_len)
			i_swap <= wp->ta_len / 2 ? trra(wp, 1) : tra(wp, 1);
		if ((tmp = check_rotates(wp)) != 0)
		{
			test_only_rotate(wp, tmp);
			break ;
		}
	}
}

void	test_only_rotate(t_wp *wp, int rotates)
{
	if (rotates <= wp->ta_len / 2)
		while (rotates-- > 0)
			tra(wp, 1);
	else
		while (rotates++ < wp->ta_len)
			trra(wp, 1);
}

void	test_sort_a(t_wp *wp)
{
	int		max_i;

	max_i = find_max_i(wp->ta, wp->ta_len);
	if (max_i == 0)
		tra(wp, 1);
	if (max_i == 1)
		trra(wp, 1);
	if (wp->ta[wp->ta_len - 1] > wp->ta[wp->ta_len - 2])
		tsa(wp, 1);
}

void	test_sort_b(t_wp *wp)
{
	int		max_i;

	if (wp->tb_len == 1)
		return ;
	if (wp->tb_len == 2)
	{
		if (wp->tb[wp->tb_len - 1] > wp->tb[wp->tb_len - 2])
			tsb(wp, 1);
		return ;
	}
	else if (wp->tb_len == 3)
	{
		max_i = find_max_i(wp->tb, wp->tb_len);
		if (max_i == 0)
			trb(wp, 1);
		if (max_i == 1)
			trrb(wp, 1);
		if (wp->tb[wp->tb_len - 1] > wp->tb[wp->tb_len - 1])
			tsb(wp, 1);
	}
}

void	test_simple_merge_sort(t_wp *wp)
{
	int		max;
	int		min;

	while (wp->ta_len > 3)
		tpb(wp, 1);
	test_sort_a(wp);
	test_sort_b(wp);
	while (wp->tb_len)
	{
		max = find_max(wp->ta, wp->ta_len);
		min = find_min(wp->ta, wp->ta_len);
		if (wp->tb[wp->tb_len - 1] < wp->ta[wp->ta_len - 1] ||
			(wp->tb[wp->tb_len - 1] > max &&
			wp->ta[wp->ta_len - 1] == min))
			tpa(wp, 1);
		tra(wp, 1);
	}
	min = find_min(wp->ta, wp->ta_len);
	while (wp->ta[wp->ta_len - 1] != min)
		tra(wp, 1);
}
