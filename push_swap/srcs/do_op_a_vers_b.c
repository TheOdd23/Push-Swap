/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_a_vers_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:20:28 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/20 08:14:24 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op_4_a(t_l **a, t_l **b, t_lim l)
{
	if ((*a) != NULL && ((*a)->in < l.m - l.l || (*a)->in > l.m + l.l))
		rotate_ab(a, b, 'r');
	else if ((*b)->next->in > (*b)->in)
		rotate(b, 'b');
}

void	do_op_3_a(t_l **a, t_l **b, t_lim l)
{
	if ((*a) != NULL && ((*a)->in < l.m - l.l || (*a)->in > l.m + l.l)
		&& (*b)->next->in > (*b)->in)
		swap_ab(a, b, 's');
	else if ((*b)->next->in > (*b)->in)
		swap(b, 'b');
}

void	do_op_1_a(t_l **a, t_l **b, t_lim l, int var)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < l.s)
	{
		if ((*a)->in == var)
		{
			push(a, b, 'b');
			size_b = ft_intlistsize(*b);
			if (var < l.m && size_b != 1)
				rotate(b, 'b');
			else if (var >= l.m && size_b > 1)
				do_op_3_a(a, b, l);
			break ;
		}
		else if ((*a)->next != NULL)
			rotate(a, 'a');
		i++;
	}
}

void	do_op_2_a(t_l **a, t_l **b, t_lim l, int var)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < l.s)
	{
		if ((*a)->in == var)
		{
			push(a, b, 'b');
			size_b = ft_intlistsize(*b);
			if (var < l.m && size_b != 1)
				rotate(b, 'b');
			else if (var >= l.m && size_b > 1)
				do_op_3_a(a, b, l);
			break ;
		}
		else if ((*a)->next != NULL)
			reverse_rotate(a, 'a');
		i++;
	}
}
