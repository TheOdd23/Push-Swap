/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:02:04 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/13 10:00:01 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			neg;
	long long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (2147483650);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

void	check_doublons(int ac, char **av, int *len)
{
	int	res;
	int	res2;
	int	i;
	int	ii;

	i = 0;
	if (*len == -1)
		i = 1;
	while (i < ac)
	{
		res = ft_atoi(av[i]);
		ii = i + 1;
		while (av[ii])
		{
			res2 = ft_atoi(av[ii]);
			if (res2 == res)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			ii++;
		}
		i++;
	}
}

void	check_digit(int ac, char **av, int *len)
{
	int	i;
	int	j;

	i = 0;
	if (*len == -1)
		i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' && ft_isdigit(av[i][1]) == 1)
			j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j])
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	check_int(int ac, char **av, int *len)
{
	long	res;
	int		i;

	i = 0;
	if (*len == -1)
		i = 1;
	while (i < ac)
	{
		res = ft_atoll(av[i]);
		if (res < -2147483648 || res > 2147483647)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		else
			i++;
	}
}

void	check_errors(int *ac, char ***av, int *len)
{
	char	**splitted;
	int		i;

	i = 0;
	if (*ac == 2)
	{
		*len = ft_nb_args((*av)[1], ' ');
		splitted = ft_split((*av)[1], ' ');
		*ac = *len;
		check_int(*ac, splitted, len);
		check_digit(*ac, splitted, len);
		check_doublons(*ac, splitted, len);
		del_tab(splitted, *ac);
		if (*ac < 2)
			exit (0);
	}
	else
	{
		check_int(*ac, *av, len);
		check_digit(*ac, *av, len);
		check_doublons(*ac, *av, len);
	}
}
