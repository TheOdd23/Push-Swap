/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:12:30 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/13 09:56:32 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 1;
	if (stack == NULL)
		return (0);
	stack = stack->next;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	create_stack_a(t_stack **a, int nb)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = malloc(sizeof(t_stack));
	temp->content = nb;
	temp->next = NULL;
	if ((*a) == NULL)
		*a = temp;
	else
	{
		temp2 = *a;
		while (temp2->next != NULL)
			temp2 = temp2->next;
			temp2->next = temp;
	}
}

void	parse_args(t_stack **a, char **av, int ac)
{
	int		i;
	int		len;
	char	**splitted;

	i = 1;
	len = -1;
	check_errors(&ac, &av, &len);
	if (len == -1)
	{
		while (i < ac)
			create_stack_a(&(*a), ft_atoi(av[i++]));
	}
	if (len != -1)
	{
		splitted = ft_split(av[1], ' ');
		i = 0;
		while (i < ac)
			create_stack_a(&(*a), ft_atoi(splitted[i++]));
		del_tab(splitted, ac);
	}
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac >= 2)
		parse_args(&a, av, ac);
	size = stack_size(a);
	if (size == 1)
		return (0);
	indexation(&a);
	read_instructions(a, b);
	return (0);
}
