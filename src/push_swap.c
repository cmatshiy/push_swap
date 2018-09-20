/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:54 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 16:18:18 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_test(t_wp *wp, int type)
{
	t_sort	*tmp;

	tmp = (t_sort *)ft_memalloc(sizeof(t_sort));
	tmp->type = type;
	ft_memcpy(wp->ta, wp->a, sizeof(int) * wp->a_len);
	wp->ta_len = wp->a_len;
	wp->tb_len = wp->b_len;
	ft_lstadd(&wp->sorts, ft_lstnew(tmp, sizeof(t_sort)));
	free(tmp);
	wp->t_len = 0;
}

void	cleanup_test(t_wp *wp)
{
	((t_sort *)wp->sorts->content)->len = wp->t_len;
	wp->t_len = 0;
}

void	run_tests(t_wp *wp, int *tmp)
{
	if ((*tmp = check_rotates(wp)) != 0)
	{
		setup_test(wp, ROTATE);
		test_only_rotate(wp, *tmp);
		cleanup_test(wp);
	}
	if (check_swaps(wp) == 1 && wp->a_len <= 5)
	{
		setup_test(wp, SWAP);
		test_only_swaps(wp);
		cleanup_test(wp);
	}
	if (wp->a_len <= 6)
	{
		setup_test(wp, MERGE);
		test_simple_merge_sort(wp);
		cleanup_test(wp);
	}
}

void	do_swaps(t_wp *wp, t_sort *min, int tmp)
{
	if (min && min->type == MERGE && wp->a_len <= 5)
	{
		simple_merge_sort(wp);
		ft_putstr(wp->printsort ? "Sort Used: Simple Sort\n" : "");
	}
	else if (min && min->type == ROTATE && wp->a_len == 5)
	{
		only_rotate(wp, tmp);
		ft_putstr(wp->printsort ? "Sort Used: Only Rotates\n" : "");
	}
	else if (min && min->type == SWAP)
	{
		only_swaps(wp);
		ft_putstr(wp->printsort ? "Sort Used: Only Swaps\n" : "");
	}
	else
	{
		merge_sort(wp);
		ft_putstr(wp->printsort ? "Sort Used: Merge Sort\n" : "");
	}
	ft_putstr(wp->printlen ? "Operation Count: " : "");
	wp->printlen ? ft_putnbr(wp->len) : ft_putstr("");
	ft_putstr(wp->printlen ? "\n" : "");
}

int		main(int ac, char **av)
{
	t_wp	wp;
	t_list	*lst;
	t_sort	*min;
	int		tmp;

	setup_env(&wp, ac, av);
	if (is_sort(&wp))
	{
		close_env(&wp);
		return (0);
	}
	run_tests(&wp, &tmp);
	lst = wp.sorts;
	min = 0;
	while (lst)
	{
		if (!min || min->len == 0 || min->len > ((t_sort *)lst->content)->len)
			min = ((t_sort *)lst->content);
		lst = lst->next;
	}
	do_swaps(&wp, min, tmp);
	close_env(&wp);
	return (0);
}
