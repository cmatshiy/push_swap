/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:06:58 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:35:22 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*find_len(t_wp *wp, int x)
{
	int *len;
	int cmp[2];
	int y;
	int found;

	len = ft_memalloc(sizeof(int) * 5);
	if (wp->b_len < 2)
		return (len);
	len[0] = wp->a_len - x - 1;
	y = wp->b_len;
	found = 0;
	while (!found && --y >= 0)
	{
		cmp[0] = wp->b[y];
		cmp[1] = (y == wp->b_len - 1) ? wp->b[0] : wp->b[y + 1];
		if (cmp[0] < wp->a[x] && cmp[1] > wp->a[x])
			found = 1;
		else if (cmp[0] < wp->a[x] && (cmp[1] == find_min(wp->b, wp->b_len)))
			found = 1;
		else if (cmp[1] > wp->a[x] && (cmp[0] == find_max(wp->b, wp->b_len)))
			found = 1;
	}
	set_len_vals(wp, len, y);
	return (len);
}

void	do_sort(t_wp *wp, int *len)
{
	if (len[2] > 1)
	{
		rotate_individuals(wp, len);
		return ;
	}
	while (len[0] > 0 && len[1] > 0)
	{
		len[2] ? rrr(wp, 1) : rr(wp, 1);
		len[0]--;
		len[1]--;
	}
	while (len[0]-- > 0)
		len[2] ? rra(wp, 1) : ra(wp, 1);
	while (len[1]-- > 0)
		len[2] ? rrb(wp, 1) : rb(wp, 1);
	pb(wp, 1);
}

void	sort_a_on_b(t_wp *wp, int len)
{
	int		i_min;
	int		count;

	i_min = 0;
	count = 0;
	while (wp->a_len > len && !is_stack_sort(wp->a, wp->a_len, 0))
	{
		i_min = find_min_i(wp->a, wp->a_len);
		if (i_min == 0)
		{
			pb(wp, 1);
			count++;
		}
		else if (i_min <= wp->a_len / 2)
			ra(wp, 1);
		else if (i_min > wp->a_len / 2)
			rra(wp, 1);
	}
}

void	merge_b_to_a(t_wp *wp)
{
	while (wp->b_len)
	{
		if (wp->b[wp->b_len - 1] < wp->a[wp->a_len - 1]
				&& wp->b[wp->b_len - 1] > wp->a[0])
			pa(wp, 1);
		else if (wp->b[wp->b_len - 1] < wp->a[wp->a_len - 1]
				&& wp->a[0] == find_max(wp->a, wp->a_len))
			pa(wp, 1);
		else if (wp->b[wp->b_len - 1] > wp->a[0]
				&& wp->a[wp->a_len - 1] == find_min(wp->a, wp->a_len))
			pa(wp, 1);
		else
		{
			if (find_pos(wp->a, wp->a_len, wp->b[wp->b_len - 1])
				> wp->a_len / 2)
				ra(wp, 1);
			else
				rra(wp, 1);
		}
	}
}

void	merge_sort(t_wp *wp)
{
	int x;

	sort_big_a_on_b(wp, 2, 0, 0);
	sort_a_on_b(wp, 2);
	merge_b_to_a(wp);
	x = find_max_i(wp->a, wp->a_len) + 1;
	if (x < wp->a_len / 2)
		while (x--)
			ra(wp, 1);
	else
		while (x++ < wp->a_len)
			rra(wp, 1);
}
