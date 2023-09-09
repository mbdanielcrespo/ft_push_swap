/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:34 by danalmei          #+#    #+#             */
/*   Updated: 2023/09/09 18:29:29 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//# include "./printf_42/ft_printf.h"

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

// Allowed functions
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

// Stack utils
void	init_stack(t_stack *stack, int max_size);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stack(const char *stack_name, const t_stack *stack);
int		is_stack_ordered(t_stack *stack);

// Parse utils
int		check_overflow(long long res);
int		ft_mod_atoi(const char *str, int *value);
int		has_duplicates(t_stack *stack);

// Utils
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
void	shift_stack_up(t_stack *stack);
void	shift_stack_down(t_stack *stack);

// Simple sort
void	order_stack_size_3(t_stack *stack);
void	order_stack_size_4(t_stack *stk, t_stack *stk_b);
void	order_stack_size_5(t_stack *stk, t_stack *stk_b);

// Radix sort
int		get_num_at_pos(int num, int pos);
int		get_max_num_of_digits(t_stack *stack);
int		digit_is_checked(t_stack *stack, int pos, int digit);
void	sort_by_num_position(t_stack *stack_a, t_stack *stack_b, int position);
void	rev_sort_num_by_pos(t_stack *stack_a, t_stack *stack_b, int position);
void		sort_negatives(t_stack *stack_a, t_stack *stack_b);
void		merge_negatives(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

void cleanup_sort(t_stack *stack_a);
#endif