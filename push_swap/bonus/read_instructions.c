/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:29:56 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/13 09:24:23 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_stack_or_error(int res, t_l *a, t_l *b, char *instructions)
{
	if (res == 0)
	{
		free (instructions);
		if (a)
			del_lists(a);
		if (b)
			del_lists(b);
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (res == 1)
		print_stacks(a, b);
}

void	check_a(t_l **a, t_l *head)
{
	if ((*a)->in > (*a)->next->in)
	{
		*a = head;
		del_lists(*a);
		write(1, "KO\n", 3);
		exit (0);
	}
	else
	{
		*a = (*a)->next;
		if ((*a)->next == NULL)
		{
			*a = head;
			del_lists(*a);
			write(1, "OK\n", 3);
			exit (0);
		}	
	}
}

void	is_in_order(t_l *a, t_l *b)
{
	t_l	*head;

	head = a;
	if (b != NULL)
	{
		if (a)
			del_lists(a);
		del_lists(b);
		write(1, "KO\n", 3);
		exit (0);
	}
	while (a != NULL)
	{
		check_a(&a, head);
	}
}

int	dispatch_instructions(t_l **a, t_l **b, char *instructions)
{
	if (ft_strncmp(instructions, "sa\n", 3) == 0)
		swap(a, 'a');
	else if (ft_strncmp(instructions, "sb\n", 3) == 0)
		swap(b, 'b');
	else if (ft_strncmp(instructions, "ss\n", 3) == 0)
		swap_ab(a, b, 's');
	else if (ft_strncmp(instructions, "ra\n", 3) == 0)
		rotate(a, 'a');
	else if (ft_strncmp(instructions, "rb\n", 3) == 0)
		rotate(b, 'b');
	else if (ft_strncmp(instructions, "rr\n", 3) == 0)
		rotate_ab(a, b, 'r');
	else if (ft_strncmp(instructions, "rra\n", 4) == 0)
		reverse_rotate(a, 'a');
	else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
		reverse_rotate(b, 'b');
	else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
		reverse_rotate_ab(a, b, 'd');
	else if (ft_strncmp(instructions, "pa\n", 3) == 0)
		push(b, a, 'a');
	else if (ft_strncmp(instructions, "pb\n", 3) == 0)
		push(a, b, 'b');
	else
		return (0);
	return (1);
}

void	read_instructions(t_l *a, t_l *b)
{
	char	*instructions;
	int		res;

	print_stacks(a, b);
	while (1)
	{
		instructions = get_next_line(0);
		if (instructions == NULL)
		{
			free (instructions);
			break ;
		}
		res = dispatch_instructions(&a, &b, instructions);
		print_stack_or_error(res, a, b, instructions);
		free (instructions);
	}
	is_in_order(a, b);
}
