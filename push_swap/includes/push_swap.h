/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:29:24 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/28 11:38:34 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct t_intlist
{
	int			content;
	int			index;
	struct t_intlist	*next;
}	t_intlist;

typedef struct t_limits
{
	int		first_limit; //limit 2
	int		second_limit; //limit 1
	int		median; //median
	int		size; //size
	int		index; //index
}	t_limits;

void		swap(t_l **a, char c);
void		push(t_l **s1, t_l **s2, char c);
void		rotate(t_l **a, char c);
void		reverse_rotate(t_l **a, char c);
void		swap_ab(t_l **a, t_l **b, char c);
void		reverse_rotate_ab(t_l **a, t_l **b, char c);
void		rotate_ab(t_l **a, t_l **b, char c);
long long	ft_atoll(const char *str);
int		in_order(int ac, char **av, int *len);
void		check_errors(int *ac, char ***av, int *len);
void		indexation(t_l **a);
void		push_swap(t_l *a, t_l *b, int size);
int		nb_args(char const *str, char c);
void		ultra_simple_swap(t_l *a, t_l *b, int size);
void		do_op_1_a(t_l **a, t_l **b, t_lim l, int var);
void		do_op_2_a(t_l **a, t_l **b, t_lim l, int var);
void		do_op_1_b(t_l **a, t_l **b, t_l **head, t_lim *l);
void		do_op_2_b(t_l **a, t_l **b, t_l **head, t_lim *l);
void		do_op_3_b(t_l **a, t_l **b, t_l **head, t_lim *l);
void		del_tab(char **splitted, int ac);
void		del_lists(t_intlist *list);
int		intlist_size(t_intlist *lst);

#endif
