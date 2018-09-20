/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:00:04 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 15:51:53 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_env(t_wp *wp)
{
	t_list *tmp;
	t_list *prev;

	free(wp->a);
	free(wp->b);
	tmp = wp->sorts;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->content);
		free(prev);
	}
	free(wp->ta);
	free(wp->tb);
}
