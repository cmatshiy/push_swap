/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:32:47 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:45:03 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_swaps(t_wp *wp)
{
	int		i_swap;
	int		cpt;
	int		tmp;

	i_swap = 0;
	while (i_swap != -1)
	{
		i_swap = get_swap(wp->a, wp->a_len);
		cpt = i_swap;
		while (cpt <= wp->a_len / 2 ? cpt-- > 0 : cpt++ < wp->a_len)
			i_swap <= wp->a_len / 2 ? ra(wp, 1) : rra(wp, 1);
		if (wp->a[wp->a_len - 1] > wp->a[wp->a_len - 2])
			sa(wp, 1);
		cpt = i_swap;
		while (cpt <= wp->a_len / 2 ? cpt-- > 0 : cpt++ < wp->a_len)
			i_swap <= wp->a_len / 2 ? rra(wp, 1) : ra(wp, 1);
		if ((tmp = check_rotates(wp)) != 0)
		{
			only_rotate(wp, tmp);
			break ;
		}
	}
}

void	only_rotate(t_wp *wp, int rotates)
{
	if (rotates <= wp->a_len / 2)
		while (rotates-- > 0)
			ra(wp, 1);
	else
		while (rotates++ < wp->a_len)
			rra(wp, 1);
}

void	sort_a(t_wp *wp)
{
	int		max_i;

	max_i = find_max_i(wp->a, wp->a_len);
	if (max_i == 0)
		ra(wp, 1);
	if (max_i == 1)
		rra(wp, 1);
	if (wp->a[wp->a_len - 1] > wp->a[wp->a_len - 2])
		sa(wp, 1);
}

void	sort_b(t_wp *wp)
{
	int		max_i;

	if (wp->b_len == 1)
		return ;
	if (wp->b_len == 2)
	{
		if (wp->b[wp->b_len - 1] > wp->b[wp->b_len - 2])
			sb(wp, 1);
		return ;
	}
	else if (wp->b_len == 3)
	{
		max_i = find_max_i(wp->b, wp->b_len);
		if (max_i == 0)
			rb(wp, 1);
		if (max_i == 1)
			rrb(wp, 1);
		if (wp->b[wp->b_len - 1] > wp->b[wp->b_len - 1])
			sb(wp, 1);
	}
}

void	simple_merge_sort(t_wp *wp)
{
	int		max;
	int		min;

	while (wp->a_len > 3)
		pb(wp, 1);
	sort_a(wp);
	sort_b(wp);
	while (wp->b_len)
	{
		max = find_max(wp->a, wp->a_len);
		min = find_min(wp->a, wp->a_len);
		if (wp->b[wp->b_len - 1] < wp->a[wp->a_len - 1] ||
				(wp->b[wp->b_len - 1] > max && wp->a[wp->a_len - 1] == min))
			pa(wp, 1);
		ra(wp, 1);
	}
	min = find_min(wp->a, wp->a_len);
	while (wp->a[wp->a_len - 1] != min)
		ra(wp, 1);
}
