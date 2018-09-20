/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:31:50 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 15:35:32 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		handle_instruction(t_wp *wp, char *line)
{
	if (ft_strequ(line, "sa"))
		sa(wp, 2);
	else if (ft_strequ(line, "sb"))
		sb(wp, 2);
	else if (ft_strequ(line, "ss"))
		ss(wp, 2);
	else if (ft_strequ(line, "pa"))
		pa(wp, 2);
	else if (ft_strequ(line, "pb"))
		pb(wp, 2);
	else if (ft_strequ(line, "ra"))
		ra(wp, 2);
	else if (ft_strequ(line, "rb"))
		rb(wp, 2);
	else if (ft_strequ(line, "rr"))
		rr(wp, 2);
	else if (ft_strequ(line, "rra"))
		rra(wp, 2);
	else if (ft_strequ(line, "rrb"))
		rrb(wp, 2);
	else if (ft_strequ(line, "rrr"))
		rrr(wp, 2);
	else
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_wp	wp;
	char	*line;

	setup_env(&wp, ac, av);
	while (ft_get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break ;
		if (handle_instruction(&wp, line))
		{
			free(line);
			close_env(&wp);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
	}
	free(line);
	if (is_sort(&wp))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	close_env(&wp);
	return (0);
}
