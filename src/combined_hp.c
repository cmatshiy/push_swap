/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_hp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:05:15 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 15:41:17 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_len_vals(t_wp *wp, int *len, int y)
{
	len[1] = wp->b_len - y - 1;
	len[4] = MAX(len[0], len[1]);
	if (len[0] + wp->b_len - len[1] < len[4])
	{
		len[4] = len[0] + wp->b_len - len[1];
		len[2] = 2;
	}
	if (wp->a_len - len[0] + len[1] < len[4])
	{
		len[4] = wp->a_len - len[0] + len[1];
		len[2] = 3;
	}
	if (MAX(wp->a_len - len[0], wp->b_len - len[1]) < len[4])
	{
		len[4] = MAX(wp->a_len - len[0], wp->b_len - len[1]);
		len[2] = 1;
		len[0] = wp->a_len - len[0];
		len[1] = wp->b_len - len[1];
	}
}

void			rotate_individuals(t_wp *wp, int *len)
{
	if (len[2] == 2)
	{
		while (len[0]-- > 0)
			ra(wp, 1);
		len[1] = wp->b_len - len[1];
		while (len[1]-- > 0)
			rrb(wp, 1);
		return ;
	}
	len[0] = wp->a_len - len[0];
	while (len[0]-- > 0)
		rra(wp, 1);
	while (len[1]-- > 0)
		rb(wp, 1);
	return ;
}

static void		setup_sort(int **best, int *len, t_wp *wp)
{
	*best = 0;
	*len = (wp->a_len > 200) ? 57 : *len;
}

void			sort_big_a_on_b(t_wp *wp, int len, int x, int *tmp)
{
	int *best;

	setup_sort(&best, &len, wp);
	while (wp->a_len > len && !(check_rotates(wp)
		|| is_stack_sort(wp->a, wp->a_len, 0)))
	{
		x = -1;
		while (++x < wp->a_len)
		{
			if (best && x >= best[4] && wp->a_len - best[4] - 1 > x)
				x = wp->a_len - best[4] - 1;
			tmp = find_len(wp, x);
			if (best == 0 || tmp[4] <= best[4])
			{
				if (best)
					free(best);
				best = tmp;
			}
			else
				free(tmp);
		}
		do_sort(wp, best);
		free(best);
		best = 0;
	}
}
