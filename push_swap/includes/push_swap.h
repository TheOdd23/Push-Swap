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

typedef struct t_stack
{
	int					content;
	int					index;
	struct t_stack	*next;
}	t_stack;

typedef struct t_limits
{
	int		first_limit;
	int		second_limit;
	int		median;
	int		size;
	int		index;
}	t_limits;

void		swap(t_stack **a, char operation);
void		push(t_stack **stack1, t_stack **stack2, char operation);
void		rotate(t_stack **a, char operation);
void		reverse_rotate(t_stack **a, char operation);
void		swap_ab(t_stack **a, t_stack **b, char operation);
void		reverse_rotate_ab(t_stack **a, t_stack **b, char operation);
void		rotate_ab(t_stack **a, t_stack **b, char operation);
long long	ft_atoll(const char *str);
int			in_order(int ac, char **av, int *len);
void		check_errors(int *ac, char ***av, int *len);
void		indexation(t_stack **a);
void		push_swap(t_stack *a, t_stack *b, int size);
int			nb_args(char const *str, char c);
void		simple_swaps(t_stack *a, t_stack *b, int size);
void		push_nb_firsthalf_to_b(t_stack **a, t_stack **b, t_limits lim, int nb_index);
void		push_nb_secondhalf_to_b(t_stack **a, t_stack **b, t_limits lim, int nb_index);
void		set_tops(t_stack **a, t_stack **b, t_limits lim);
void		push_nb_firsthalf_to_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim);
void		push_nb_secondhalf_to_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim);
void		set_top_a(t_stack **a, t_stack **b, t_stack **head, t_limits *lim);
void		del_tab(char **splitted, int ac);
void		del_stacks(t_stack *stack);
int			stack_size(t_stack *stack);

#endif
