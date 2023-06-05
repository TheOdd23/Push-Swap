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

void	final_sort(t_stack **a, t_stack **b, t_limits lim)
{
	t_stack	*head;

	head = *b;
	while (lim.index <= lim.size)
	{
		if (((*b)->index == lim.size || (*b)->index == lim.size - 1)
			&& lim.index <= lim.size / 2)
			push_nb_firsthalf_to_a(a, b, &head, &lim);
		else if (((*b)->index == lim.size || (*b)->index == lim.size -1)
			&& lim.index > lim.size / 2)
			push_nb_secondhalf_to_a(a, b, &head, &lim);
		else
		{
			*b = (*b)->next;
			lim.index++;
		}
	}
}

void	presort_op_dispatcher(t_stack **a, t_stack **b, int nb_index, t_limits *lim)
{
	if ((nb_index < (*lim).median && (*lim).index <= (*lim).size / 2)
		|| (nb_index >= (*lim).median && (*lim).index <= (*lim).size / 2))
		push_nb_firsthalf_to_b(a, b, *lim, nb_index);
	else if ((nb_index < (*lim).median && (*lim).index > (*lim).size / 2)
		|| (nb_index >= (*lim).median && (*lim).index > (*lim).size / 2))
		push_nb_secondhalf_to_b(a, b, *lim, nb_index);
	(*lim).size--;
	(*lim).index = 0;
}

void	presort(t_stack **a, t_stack **b, t_limits *lim)
{
	int		nb_index;
	t_stack	*head;

	head = *a;
	while ((*lim).index < (*lim).size)
	{
		if ((*a)->index >= (*lim).median - (*lim).first_limit
			&& (*a)->index <= (*lim).median + (*lim).first_limit)
		{
			nb_index = (*a)->index;
			*a = head;
			presort_op_dispatcher(a, b, nb_index, lim);
			head = *a;
		}
		else
		{
			*a = (*a)->next;
			(*lim).index++;
			if ((*lim).index == (*lim).size)
			{
				*a = head;
				(*lim).index = 0;
				(*lim).first_limit += (*lim).second_limit;
			}
		}
	}
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	t_limits	lim;

	lim.size = size;
	lim.median = size / 2;
	lim.index = 0;
	if (size <= 100)
	{
		lim.first_limit = 10;
		lim.second_limit = 10;
	}
	else if (size <= 500)
	{
		lim.first_limit = 29;
		lim.second_limit = 29;
	}
	else
	{
		lim.first_limit = 50;
		lim.second_limit = 50;
	}
	presort(&a, &b, &lim);
	lim.size = size - 1;
	lim.index = 0;
	final_sort(&a, &b, lim);
	del_stacks(a);
}
