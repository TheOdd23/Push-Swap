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

void	size3_swap(t_stack **a)
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

void	size4_swap(t_stack **a, t_stack **b)
{
	while (*a != NULL)
	{
		if ((*a)->index == 0)
		{
			push(a, b, 'b');
			if ((*a)->index > (*a)->next->index
				|| (*a)->next->index > (*a)->next->next->index)
				size3_swap(a);
			push(b, a, 'a');
			break ;
		}
		else
			rotate(a, 'a');
	}
}

void	size5_endswap(t_stack **a, t_stack **b)
{
	if ((*b)->index > (*b)->next->index)
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

void	size5_swap(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*a != NULL)
	{
		if ((*a)->index == 0 || (*a)->index == 4)
		{
			push(a, b, 'b');
			i++;
			if (i == 2)
			{
				if ((*a)->index > (*a)->next->index
					|| (*a)->next->index > (*a)->next->next->index)
					size3_swap(a);
				break ;
			}
		}
		else
			rotate(a, 'a');
	}
	size5_endswap(a, b);
}

void	simple_swaps(t_stack *a, t_stack *b, int size)
{
	if (size == 3)
		size3_swap(&a);
	else if (size == 4)
		size4_swap(&a, &b);
	else if (size == 5)
		size5_swap(&a, &b);
	else if (size == 2 && a->content > a->next->content)
		rotate(&a, 'a');
	del_stacks(a);
}
