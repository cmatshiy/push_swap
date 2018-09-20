/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:57:46 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 15:50:25 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int		debug_print(t_wp *wp)
{
	int i;

	if (!wp->debug)
		return (0);
	if (wp->printslow)
	{
		nanosleep(&(struct timespec) {0, 60000000}, 0);
		ft_putstr("\e[1;1H\e[2J");
	}
	wp->color ? ft_putstr(RED) : ft_putstr("");
	ft_putendl("Stack A:");
	i = wp->a_len;
	wp->color ? ft_putstr(GREEN) : ft_putstr("");
	while (i--)
		ft_putendl(ft_itoa(wp->a[i]));
	wp->color ? ft_putstr(RED) : ft_putstr("");
	ft_putendl("Stack B:");
	i = wp->b_len;
	wp->color ? ft_putstr(BLUE) : ft_putstr("");
	while (i--)
		ft_putendl(ft_itoa(wp->b[i]));
	ft_putendl("");
	wp->color ? ft_putstr(NC) : ft_putstr("");
	return (0);
}

int		check_duplicates(t_wp *wp)
{
	int		x;
	int		y;

	x = -1;
	while (++x < wp->a_len)
	{
		y = -1;
		while (++y < wp->a_len)
			if (x != y && wp->a[x] == wp->a[y])
				return (-1);
	}
	return (0);
}

void	handle_options(int *ac, char ***av, t_wp *wp)
{
	int x;

	x = -1;
	while (++x < *ac)
	{
		if (*ac > 1 && ft_strequ((*av)[x], "-d"))
			wp->debug = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-c"))
			wp->color = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-p"))
			wp->printsort = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-l"))
			wp->printlen = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-s"))
			wp->printslow = 1;
		else
			continue;
		wp->a_len--;
		(*ac)--;
		x--;
		(*av)++;
	}
	return ;
}

int		handle_args(int ac, char **av, t_wp *wp)
{
	int		i;
	int		x;
	long	tmp;

	handle_options(&ac, &av, wp);
	i = 0;
	while (++i < ac)
	{
		x = -1;
		while (av[i][++x])
			if ((!ft_isdigit(av[i][x])) && !(av[i][x] == '-' && x == 0))
				return (-1);
		if (x == 0)
			return (-1);
		if (x > 11)
			return (-1);
		tmp = ft_atoi(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (-1);
		wp->a[ac - 1 - i] = (int)tmp;
	}
	return (0);
}

void	setup_env(t_wp *wp, int ac, char **av)
{
	wp->a = ft_memalloc(sizeof(int) * (ac - 1));
	wp->b = ft_memalloc(sizeof(int) * (ac - 1));
	wp->ta = ft_memalloc(sizeof(int) * (ac - 1));
	wp->tb = ft_memalloc(sizeof(int) * (ac - 1));
	wp->a_len = ac - 1;
	wp->b_len = 0;
	wp->len = 0;
	wp->debug = 0;
	wp->color = 0;
	wp->printsort = 0;
	wp->printlen = 0;
	wp->printslow = 0;
	if (handle_args(ac, av, wp) || check_duplicates(wp)
			|| wp->a_len == 0)
	{
		free(wp->a);
		free(wp->b);
		free(wp->ta);
		free(wp->tb);
		if (wp->a_len != 0)
			ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
