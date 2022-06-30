/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:41:36 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/15 15:35:21 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	in_order(int ac, char **av, int *len)
{
	int	i;

	i = 0;
	if (*len == -1)
		i = 1;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_intlistsize(t_l *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	lst = lst->next;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	create_stack_a(t_l **a, int nb)
{
	t_l	*temp;
	t_l	*temp2;

	temp = malloc(sizeof(t_l));
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

void	parse_args(t_l **a, char **av, int ac)
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
	t_l		*a;
	t_l		*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac >= 2)
		parse_args(&a, av, ac);
	size = ft_intlistsize(a);
	if (size == 1)
		return (0);
	indexation(&a);
	if (size >= 2 && size <= 5)
	{
		ultra_simple_swap(a, b, size);
		return (0);
	}
	push_swap(a, b, size);
	return (0);
}
