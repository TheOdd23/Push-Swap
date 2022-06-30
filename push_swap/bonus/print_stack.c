/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:17:25 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/09 07:31:36 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_stack_a(t_l *a)
{
	while (a != NULL)
	{
		ft_printf("%d  |  x\n", a->in);
		a = a->next;
		if (a == NULL)
			return ;
	}
}

void	print_stack_b(t_l *b)
{
	while (b != NULL)
	{
		ft_printf("x  |  %d\n", b->in);
		b = b->next;
		if (b == NULL)
			return ;
	}
}

void	print_motifs(void)
{
	ft_printf("---------\n");
	ft_printf("a   |   b\n");
	ft_printf("---------\n");
	ft_printf("\n");
}

void	print_stacks(t_l *a, t_l *b)
{
	ft_printf("\n");
	while (a != NULL || b != NULL)
	{
		if (b == NULL)
		{
			print_stack_a(a);
			break ;
		}
		else if (a == NULL)
		{
			print_stack_b(b);
			break ;
		}
		else
		{
			ft_printf("%d  |  %d\n", a->in, b->in);
			a = a->next;
			b = b->next;
		}
	}
	print_motifs();
}
