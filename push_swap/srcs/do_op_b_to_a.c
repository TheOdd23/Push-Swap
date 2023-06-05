/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_b_vers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:01:07 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/20 07:42:35 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Find biggest or second to biggest in first half of b and pushes it on top of stack a
void	push_nb_firsthalf_to_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	*b = *head;
	while ((*b)->index != (*lim).size && (*b)->index != (*lim).size - 1)
	{
		rotate(b, 'b');
		*head = *b;
	}
	if ((*b)->index == (*lim).size)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL
			&& ((*a)->index > (*a)->next->index))
			set_top_a(a, b, head, lim);
		(*lim).index = 0;
		(*lim).size--;
	}
	else if ((*b)->index == (*lim).size - 1)
	{
		push(b, a, 'a');
		(*head) = (*b);
		(*lim).index = 0;
	}
}

//Find biggest or second to biggest in second half of b and pushes it on top of stack a
void	push_nb_secondhalf_to_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	*b = *head;
	while ((*b)->index != (*lim).size - 1 && (*b)->index != (*lim).size)
	{
		reverse_rotate(b, 'b');
		*head = *b;
	}
	if ((*b)->index == (*lim).size)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL && ((*a)->index > (*a)->next->index))
			set_top_a(a, b, head, lim);
		(*lim).size--;
	}
	else if ((*b)->index == (*lim).size - 1)
	{
		push(b, a, 'a');
		*head = *b;
	}
	(*lim).index = 0;
}

//Looks if top number is bigger than the one after, switch those numbers if it is the case
void	set_top_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	if ((*b) != NULL && (*b)->next != NULL
		&& ((*b)->index < (*b)->next->index))
	{
		swap_ab(a, b, 's');
		*head = *b;
	}
	else
		swap(a, 'a');
	(*lim).size--;
}
