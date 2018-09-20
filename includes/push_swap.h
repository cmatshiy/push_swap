/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:10:55 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/17 17:27:45 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define NC "\033[0m"
# define ABS(x) ((x) < 0 ? (-x) : (x))

enum			e_sort
{
	MERGE,
	ROTATE,
	SWAP,
	SLOW
};

typedef struct	s_sort
{
	int		len;
	int		type;
}				t_sort;

typedef struct	s_wp
{
	int		*a;
	int		*b;
	int		*ta;
	int		*tb;
	int		a_len;
	int		b_len;
	int		ta_len;
	int		tb_len;
	int		t_len;
	t_list	*sorts;
	char	debug : 1;
	char	color : 1;
	char	printsort : 1;
	char	printlen : 1;
	char	printslow : 1;
	int		len;
}				t_wp;

void			setup_env(t_wp *wp, int ac, char **av);
int				is_sort(t_wp *wp);
void			only_rotate(t_wp *wp, int rotates);
void			only_swaps(t_wp *wp);
int				get_swap(int *arr, int len);
int				check_swaps(t_wp *wp);
int				check_rotates(t_wp *wp);
int				find_max(int *arr, int len);
int				find_min(int *arr, int len);
int				find_max_i(int *arr, int len);
int				find_min_i(int *arr, int len);
void			simple_merge_sort(t_wp *wp);
int				debug_print(t_wp *wp);
void			slow_sort(t_wp *wp);
int				find_mid(int *arr, int len);
void			merge_sort(t_wp *wp);
int				is_stack_sort(int *arr, int len, char rev);
int				*find_len(t_wp *wp, int x);
int				find_pos(int *arr, int len, int val);
void			close_env(t_wp *wp);
void			set_len_vals(t_wp *wp, int *len, int y);
void			rotate_individuals(t_wp *wp, int *len);
void			sort_big_a_on_b(t_wp *wp, int len, int x, int *tmp);
void			do_sort(t_wp *wp, int *len);

void			pb(t_wp *wp, char swap);
void			pa(t_wp *wp, char swap);
void			sa(t_wp *wp, char swap);
void			sb(t_wp *wp, char swap);
void			ss(t_wp *wp, char swap);
void			ra(t_wp *wp, char swap);
void			rb(t_wp *wp, char swap);
void			rr(t_wp *wp, char swap);
void			rra(t_wp *wp, char swap);
void			rrb(t_wp *wp, char swap);
void			rrr(t_wp *wp, char swap);

void			tpb(t_wp *wp, char swap);
void			tpa(t_wp *wp, char swap);
void			tsa(t_wp *wp, char swap);
void			tsb(t_wp *wp, char swap);
void			tss(t_wp *wp, char swap);
void			tra(t_wp *wp, char swap);
void			trb(t_wp *wp, char swap);
void			trr(t_wp *wp, char swap);
void			trra(t_wp *wp, char swap);
void			trrb(t_wp *wp, char swap);
void			trrr(t_wp *wp, char swap);

void			test_only_rotate(t_wp *wp, int rotates);
void			test_only_swaps(t_wp *wp);
void			test_simple_merge_sort(t_wp *wp);
void			test_slow_sort(t_wp *wp);

#endif
