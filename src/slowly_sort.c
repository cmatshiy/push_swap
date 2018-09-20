/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slowly_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:54:48 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:47:50 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slow_sort(t_wp *wp)
{
	int		i_min;

	i_min = 0;
	while (wp->a_len)
	{
		i_min = find_min_i(wp->a, wp->a_len);
		if (i_min == 0)
			pb(wp, 1);
		else if (i_min == 1)
			sa(wp, 1);
		else if (i_min <= wp->a_len / 2)
			ra(wp, 1);
		else if (i_min > wp->a_len / 2)
			rra(wp, 1);
	}
	while (wp->b_len)
		pa(wp, 1);
}

void	test_slow_sort(t_wp *wp)
{
	int		i_min;

	i_min = 0;
	while (wp->ta_len)
	{
		i_min = find_min_i(wp->ta, wp->ta_len);
		if (i_min == 0)
			tpb(wp, 1);
		else if (i_min == 1)
			tsa(wp, 1);
		else if (i_min <= wp->a_len / 2)
			tra(wp, 1);
		else if (i_min > wp->a_len / 2)
			trra(wp, 1);
	}
	while (wp->b_len)
		tpa(wp, 1);
}
