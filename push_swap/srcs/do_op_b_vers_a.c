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

void	do_op_4_b(t_l **a, t_l **b, t_l **head, t_lim *l)
{
	if ((*b) != NULL && (*b)->next != NULL
		&& ((*b)->in < (*b)->next->in))
	{
		swap_ab(a, b, 's');
		*head = *b;
	}
	else
		swap(a, 'a');
	(*l).s--;
}

void	do_op_1_b(t_l **a, t_l **b, t_l **head, t_lim *l)
{
	*b = *head;
	while ((*b)->in != (*l).s)
	{
		rotate(b, 'b');
		*head = *b;
		if ((*b)->in == (*l).s)
			break ;
	}
	if ((*b)->in == (*l).s)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL
			&& ((*a)->in > (*a)->next->in))
			do_op_4_b(a, b, head, l);
	(*l).i = 0;
	(*l).s--;
	}
}

void	do_op_2_b(t_l **a, t_l **b, t_l **head, t_lim *l)
{
	(*b) = (*head);
	while ((*b)->in != (*l).s - 1)
	{
		rotate(b, 'b');
		*head = *b;
		if ((*b)->in == (*l).s - 1)
			break ;
	}
	if ((*b)->in == (*l).s - 1)
	{
		push(b, a, 'a');
		(*head) = (*b);
		(*l).i = 0;
	}
}

void	do_op_3_b(t_l **a, t_l **b, t_l **head, t_lim *l)
{
	*b = *head;
	while ((*b)->in != (*l).s - 1 || (*b)->in != (*l).s)
	{
		reverse_rotate(b, 'b');
		*head = *b;
		if ((*b)->in == (*l).s - 1 || (*b)->in == (*l).s)
			break ;
	}
	if ((*b)->in == (*l).s)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL && ((*a)->in > (*a)->next->in))
			do_op_4_b(a, b, head, l);
		(*l).s--;
	}
	else if ((*b)->in == (*l).s - 1)
	{
		push(b, a, 'a');
		*head = *b;
	}
	(*l).i = 0;
}
