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

void	current_min(long	*intmin, t_l *stack, t_l **currentintmin)
{
	*intmin = stack->content;
	*currentintmin = stack;
}

void	int_min(long *intmin, t_l *stack, t_l **currentintmin,
		long *previntmin)
{
	int			i;
	int			size;
	t_l			*head;

	i = 0;
	size = ft_intlistsize(stack);
	head = stack;
	while (i < size)
	{
		if (stack->content < *intmin && stack->content > *previntmin)
			current_min(&(*intmin), stack, &(*currentintmin));
		else
		{
			stack = stack->next;
			if (stack == NULL)
			{
				stack = *currentintmin;
				stack->in = i;
				i++;
				*previntmin = stack->content;
				stack = head;
				*intmin = 2147483650;
			}
		}
	}
}

void	int_max(long *intmax, t_l *stack)
{
	while (stack != NULL)
	{
		if (stack->content > *intmax)
			*intmax = stack->content;
		else
			stack = stack->next;
	}
}

void	indexation(t_l **a)
{
	t_l		*head;
	t_l		*currentintmin;
	long	intmax;
	long	intmin;
	long	previntmin;

	previntmin = -2147483750;
	intmax = -2147483650;
	intmin = 2147483650;
	head = (*a);
	int_max(&intmax, (*a));
	*a = head;
	int_min(&intmin, *a, &currentintmin, &previntmin);
}
