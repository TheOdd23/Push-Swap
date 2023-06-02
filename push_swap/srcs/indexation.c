/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:15:39 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/09 07:58:22 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	current_smallest(long *smallest_nb, t_stack *stack, t_stack **current_smallest_nb)
{
	*smallest_nb = stack->content;
	*current_smallest_nb = stack;
}

void	find_smallest_nb(long *smallest_nb, t_stack *stack, t_stack **current_smallest_nb,
		long *prev_smallest_nb)
{
	int		i;
	int		size;
	t_stack	*head;

	i = 0;
	size = stack_size(stack);
	head = stack;
	while (i < size)
	{
		if (stack->content < *smallest_nb && stack->content > *prev_smallest_nb)
			current_smallest(&(*smallest_nb), stack, &(*current_smallest_nb));
		else
		{
			stack = stack->next;
			if (stack == NULL)
			{
				stack = *current_smallest_nb;
				stack->index = i;
				i++;
				*prev_smallest_nb = stack->content;
				stack = head;
				*smallest_nb = 2147483650;
			}
		}
	}
}

void	find_biggest_nb(long *biggest_nb, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->content > *biggest_nb)
			*biggest_nb = stack->content;
		else
			stack = stack->next;
	}
}

void	indexation(t_stack **a)
{
	t_stack	*head;
	t_stack	*current_smallest_nb;
	long	biggest_nb;
	long	smallest_nb;
	long	prev_smallest_nb;

	prev_smallest_nb = -2147483750;
	biggest_nb = -2147483650;
	smallest_nb = 2147483650;
	head = (*a);
	find_biggest_nb(&biggest_nb, (*a));
	*a = head;
	find_smallest_nb(&smallest_nb, *a, &current_smallest_nb, &prev_smallest_nb);
}
