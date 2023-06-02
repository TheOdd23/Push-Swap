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

void	swap(t_stack **stack, char operation)
{
	t_stack	*head;
	t_stack	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = head;
	head->next = temp;
	if (operation == 'a')
		write(1, "sa\n", 3);
	else if (operation == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_stack **stack, char operation)
{
	t_stack	*head;
	t_stack	*temp;

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
	if (operation == 'a')
		write(1, "ra\n", 3);
	else if (operation == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, char operation)
{	
	t_stack	*pre_last;
	t_stack	*last;

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
	if (operation == 'a')
		write(1, "rra\n", 4);
	else if (operation == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_stack **stack1, t_stack **stack2, char operation)
{
	t_stack	*temp;

	temp = *stack1;
	if (!(*stack1))
		return ;
	*stack1 = (*stack1)->next;
	temp->next = *stack2;
	*stack2 = temp;
	if (operation == 'a')
		write(1, "pa\n", 3);
	else if (operation == 'b')
		write(1, "pb\n", 3);
}
