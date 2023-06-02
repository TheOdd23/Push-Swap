/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:34:33 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/08 07:26:12 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ab(t_stack **a, t_stack **b, char operation)
{
	swap(a, 'm');
	swap(b, 'm');
	if (operation == 's')
		write(1, "ss\n", 3);
}

void	rotate_ab(t_stack **a, t_stack **b, char operation)
{
	rotate(a, 'm');
	rotate(b, 'm');
	if (operation == 'r')
		write(1, "rr\n", 3);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, char operation)
{
	reverse_rotate(a, 'm');
	reverse_rotate(b, 'm');
	if (operation == 'd')
		write(1, "rrr\n", 3);
}
