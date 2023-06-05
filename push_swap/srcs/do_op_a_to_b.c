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

//Find nb in range in first half of 'a', demanding less actions, to push in b.
//Check if that number is bigger or smaller than median, then sets it on top or bottom
void	push_nb_firsthalf_to_b(t_stack **a, t_stack **b, t_limits lim, int nb_index)
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
				set_tops(a, b, lim);
			break ;
		}
		else if ((*a)->next != NULL)
			rotate(a, 'a');
		i++;
	}
}

//Find nb in range in second half of 'a', demanding less actions, to push in b.
//Check if that number is bigger or smaller than median, then sets it on top or bottom
void	push_nb_secondhalf_to_b(t_stack **a, t_stack **b, t_limits lim, int nb_index)
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
				set_tops(a, b, lim);
			break ;
		}
		else if ((*a)->next != NULL)
			reverse_rotate(a, 'a');
		i++;
	}
}

//Starts by checking if first number in stack 'a' isn't in range
//Then check if the second number in stack 'b' is bigger than the one on top
//If both checks out, swap both of the tops, if b checks out, swap top b
void	set_tops(t_stack **a, t_stack **b, t_limits lim)
{
	if ((*a) != NULL && ((*a)->index < lim.median - lim.first_limit
			|| (*a)->index > lim.median + lim.first_limit)
		&& (*b)->next->index > (*b)->index)
		swap_ab(a, b, 's');
	else if ((*b)->next->index > (*b)->index)
		swap(b, 'b');
}
