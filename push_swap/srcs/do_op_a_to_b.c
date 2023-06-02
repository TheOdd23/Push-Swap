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

void	do_op_nb_in_first_half_a(t_stack **a, t_stack **b, t_limits lim, int nb_index)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < lim.size)
	{
		if ((*a)->index == nb_index)
		{
			push(a, b, 'b');
			size_b = stack_size(*b);
			if (nb_index < lim.median && size_b != 1)
				rotate(b, 'b');
			else if (nb_index >= lim.median && size_b > 1)
				do_op_set_tops(a, b, lim);
			break ;
		}
		else if ((*a)->next != NULL)
			rotate(a, 'a');
		i++;
	}
}

void	do_op_nb_in_second_half_a(t_stack **a, t_stack **b, t_limits lim, int nb_index)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < lim.size)
	{
		if ((*a)->index == nb_index)
		{
			push(a, b, 'b');
			size_b = stack_size(*b);
			if (nb_index < lim.median && size_b != 1)
				rotate(b, 'b');
			else if (nb_index >= lim.median && size_b > 1)
				do_op_set_tops(a, b, lim);
			break ;
		}
		else if ((*a)->next != NULL)
			reverse_rotate(a, 'a');
		i++;
	}
}

void	do_op_set_tops(t_stack **a, t_stack **b, t_limits lim)
{
	if ((*a) != NULL && ((*a)->index < lim.median - lim.first_limit || (*a)->index > lim.median + lim.first_limit)
		&& (*b)->next->index > (*b)->index)
		swap_ab(a, b, 's');
	else if ((*b)->next->index > (*b)->index)
		swap(b, 'b');
}

void	do_op_4_a(t_stack **a, t_stack **b, t_limits lim)
{
	if ((*a) != NULL && ((*a)->index < lim.median - lim.first_limit || (*a)->index > lim.median + lim.first_limit))
		rotate_ab(a, b, 'r');
	else if ((*b)->next->index > (*b)->index)
		rotate(b, 'b');
}