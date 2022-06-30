/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:36:29 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/13 09:25:33 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_l **stack, char c)
{
	t_l	*head;
	t_l	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = head;
	head->next = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_l **stack, char c)
{
	t_l	*head;
	t_l	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	temp = *stack;
	*stack = (*stack)->next;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			temp->next = head;
			head->next = NULL;
		}
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_l **stack, char c)
{	
	t_l	*pre_last;
	t_l	*last;

	last = *stack;
	pre_last = NULL;
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_l **s1, t_l **s2, char c)
{
	t_l	*temp;

	temp = *s1;
	if (!(*s1))
		return ;
	*s1 = (*s1)->next;
	temp->next = *s2;
	*s2 = temp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
