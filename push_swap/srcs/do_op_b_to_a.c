/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_b_vers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:01:07 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/20 07:42:35 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Trouve le plus grand chiffre dans la premiere moitie de b et le push dans le a*/
void	do_op_1_b(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	*b = *head;
	while ((*b)->index != (*lim).size)
	{
		rotate(b, 'b');
		*head = *b;
		if ((*b)->index == (*lim).size)
			break ;
	}
/*À revoir, peut-être faire comme doop3 et mettre 1 et 2 ensemble*/
	if ((*b)->index == (*lim).size)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL
			&& ((*a)->index > (*a)->next->index))
			do_op_4_b(a, b, head, lim);
		(*lim).index = 0;
		(*lim).size--;
	}
}

/*Trouve l'avant-dernier plus grand chiffre dans la premiere moitie de b et le push dans le a*/
void	do_op_2_b(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	*b = *head;
	while ((*b)->index != (*lim).size - 1)
	{
		rotate(b, 'b');
		*head = *b;
		if ((*b)->index == (*lim).size - 1)
			break ;
	}
/*À revoir*/
	if ((*b)->index == (*lim).size - 1)
	{
		push(b, a, 'a');
		(*head) = (*b);
		(*lim).index = 0;
	}
}

/*Trouve le derneir ou l'avant-dernier plus grand chiffre dans la deuxieme moitié de b et le push dans le a*/
void	do_op_3_b(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	*b = *head;
	while ((*b)->index != (*lim).size - 1 || (*b)->index != (*lim).size)
	{
		reverse_rotate(b, 'b');
		*head = *b;
		if ((*b)->index == (*lim).size - 1 || (*b)->index == (*lim).size)
			break ;
	}
	if ((*b)->index == (*lim).size)
	{
		push(b, a, 'a');
		*head = *b;
		if ((*a)->next != NULL && ((*a)->index > (*a)->next->index))
			do_op_4_b(a, b, head, lim);
		(*lim).size--;
	}
	else if ((*b)->index == (*lim).size - 1)
	{
		push(b, a, 'a');
		*head = *b;
	}
	(*lim).index = 0;
}

/*Vérifie s'il s'agit du plus grand nombre sur le dessus, sinon inverse les deux du dessus*/
void	(t_stack **a, t_stack **b, t_stack **head, t_limits *lim)
{
	if ((*b) != NULL && (*b)->next != NULL
		&& ((*b)->index < (*b)->next->index))
	{
		swap_ab(a, b, 's');
		*head = *b;
	}
	else
		swap(a, 'a');
	(*lim).size--;
}
