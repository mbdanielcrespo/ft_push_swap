/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:34 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:55:42 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./printf_42/ft_printf.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_stack
{
	int	size;
	int	*data;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);

void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	init_stack(t_stack *stack, int max_size);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stack(const char *stack_name, const t_stack *stack);
int		is_stack_ordered(t_stack *stack);

int		rotations_to_sort(t_stack *stack);
int		is_circularly_sorted(t_stack *stack);
int		has_duplicates(t_stack *stack);

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
void	shift_stack_up(t_stack *stack);
void	shift_stack_down(t_stack *stack);

void	perform_rotations_a(t_stack *stack, int rotations);
void	perform_rotations_b(t_stack *stack, int rotations);
void	perform_rotations_both(t_stack *stack_a, t_stack *stack_b, int rot);

int		ft_index_of_min(t_stack *stk);
int		calculate_r_both(int r_a, int r_b);
int		calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index);
int		calculate_ops(t_stack *stack_a, t_stack *stack_b, int index);

void	order_stack_size_3(t_stack *stack);
void	order_stack_size_4(t_stack *stk, t_stack *stk_b);
void	order_stack_size_5(t_stack *stk, t_stack *stk_b);
void	order_next_num(t_stack *stack_a, t_stack *stack_b);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);

#endif