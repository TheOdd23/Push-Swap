/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:41:27 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/08 13:38:55 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/push_swap_bonus.h"

int	check_instructions(char *instructions)
{
	if (ft_strncmp(instructions, "sa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "ss\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "ra\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "rra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instructions, "pa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(instructions, "pb\n", 3) == 0)
		return (1);
	return (0);
}

char	*stash_trim(char *stash)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (stash[0] == '\0' || stash[0] == '\n'
		|| check_instructions(stash) == 0)
	{
		free (stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	trimmed = ft_calloc(sizeof(char), ((ft_strlen(stash) - i) + 1));
	while (stash[i])
		trimmed[j++] = stash[i++];
	free (stash);
	return (trimmed);
}

char	*create_new_line(char *stash)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 1));
	j = 0;
	while (j < i)
	{
		new_line[j] = stash[j];
		j++;
	}
	return (new_line);
}

char	*create_stash(char *stash, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_calloc(sizeof(char), (ft_strlen(stash) + ft_strlen(buffer) + 1));
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	free (stash);
	return (temp);
}
