/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:59:47 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/08 13:36:38 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/push_swap_bonus.h"

char	*get_next_line(int fd)
{	
	static char	*stash;
	char		*new_line;

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(sizeof(char), 5);
	stash = create_buffer(stash, fd);
	new_line = create_new_line(stash);
	stash = stash_trim(stash);
	return (new_line);
}

char	*create_buffer(char *stash, int fd)
{
	char	buffer[6];
	int		res;

	res = 1;
	while (res > 0 && ft_strchr(stash, '\n') == 0)
	{
		res = read(fd, buffer, 5);
		buffer[res] = '\0';
		stash = create_stash(stash, buffer);
	}
	return (stash);
}
