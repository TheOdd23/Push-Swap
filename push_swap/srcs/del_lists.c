/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:39:37 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/07 10:55:01 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_lists(t_l *list)
{
	t_l	*temp;

	temp = list;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
}

void	del_tab(char **splitted, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
