/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:19:21 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/07 11:25:04 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	really_simple_swap(t_l **a, t_l **b)
{
	if ((*b)->in > (*b)->next->in)
	{
		push(b, a, 'a');
		rotate(a, 'a');
		push(b, a, 'a');
	}
	else
	{
		push(b, a, 'a');
		push(b, a, 'a');
		rotate(a, 'a');
	}
}

void	simple_swap(t_l **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
		{
			if ((*a)->content > (*a)->next->next->content)
				rotate(a, 'a');
			else
				swap(a, 'a');
		}
		else
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
	}
	else if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->content > (*a)->next->next->content)
			reverse_rotate(a, 'a');
		else
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
	}
}

void	still_simple_swap(t_l **a, t_l **b)
{
	while (*a != NULL)
	{
		if ((*a)->in == 0)
		{
			push(a, b, 'b');
			if ((*a)->in > (*a)->next->in
				|| (*a)->next->in > (*a)->next->next->in)
				simple_swap(a);
			push(b, a, 'a');
			break ;
		}
		else
			rotate(a, 'a');
	}
}

void	relatively_simple_swap(t_l **a, t_l **b)
{
	int	i;

	i = 0;
	while (*a != NULL)
	{
		if ((*a)->in == 0 || (*a)->in == 4)
		{
			push(a, b, 'b');
			i++;
			if (i == 2)
			{
				if ((*a)->in > (*a)->next->in
					|| (*a)->next->in > (*a)->next->next->in)
					simple_swap(a);
				break ;
			}
		}
		else
			rotate(a, 'a');
	}
	really_simple_swap(a, b);
}

void	ultra_simple_swap(t_l *a, t_l *b, int size)
{
	if (size == 3)
		simple_swap(&a);
	else if (size == 4)
		still_simple_swap(&a, &b);
	else if (size == 5)
		relatively_simple_swap(&a, &b);
	else if (size == 2 && a->content > a->next->content)
		rotate(&a, 'a');
	del_lists(a);
}
