/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:27:49 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/28 11:38:22 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_sort(t_l **a, t_l **b, t_lim l)
{
	t_l	*head;

	head = *b;
	while (l.i <= l.s)
	{
		if (((*b)->in == l.s || (*b)->in == l.s - 1) && l.i <= l.s / 2)
		{
			if ((*b)->in == l.s)
				do_op_1_b(a, b, &head, &l);
			else if ((*b)->in == l.s - 1)
				do_op_2_b(a, b, &head, &l);
		}
		else if (((*b)->in == l.s || (*b)->in == l.s -1) && l.i > l.s / 2)
			do_op_3_b(a, b, &head, &l);
		else
		{
			*b = (*b)->next;
			l.i++;
		}
	}
}

void	presort2(t_l **a, t_l **b, int var, t_lim *l)
{
	if ((var < (*l).m && (*l).i <= (*l).s / 2)
		|| (var >= (*l).m && (*l).i <= (*l).s / 2))
		do_op_1_a(a, b, *l, var);
	else if ((var < (*l).m && (*l).i > (*l).s / 2)
		|| (var >= (*l).m && (*l).i > (*l).s / 2))
		do_op_2_a(a, b, *l, var);
	(*l).s--;
	(*l).i = 0;
}

void	presort(t_l **a, t_l **b, t_lim *l)
{
	int	var;
	t_l	*head;

	head = *a;
	while ((*l).i < (*l).s)
	{
		if ((*a)->in >= (*l).m - (*l).l && (*a)->in <= (*l).m + (*l).l)
		{
			var = (*a)->in;
			*a = head;
			presort2(a, b, var, l);
			head = *a;
		}
		else
		{
			*a = (*a)->next;
			(*l).i++;
			if ((*l).i == (*l).s)
			{
				*a = head;
				(*l).i = 0;
				(*l).l += (*l).l2;
			}
		}
	}
}

void	push_swap(t_l *a, t_l *b, int size)
{
	t_lim	l;

	l.s = size;
	l.m = size / 2;
	l.i = 0;
	if (size <= 100)
	{
		l.l = 10;
		l.l2 = 10;
	}
	else if (size <= 500)
	{
		l.l = 29;
		l.l2 = 29;
	}
	else
	{
		l.l = 50;
		l.l2 = 50;
	}
	presort(&a, &b, &l);
 	l.s = size - 1;
	l.i = 0;
	final_sort(&a, &b, l);
	del_lists(a);
}
