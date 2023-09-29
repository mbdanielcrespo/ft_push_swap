/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:33:45 by danalmei          #+#    #+#             */
/*   Updated: 2023/09/09 18:33:08 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num_at_pos(int num, int pos)
{
	while (pos != 0)
	{
		num = num / 10;
		pos--;
	}
	return (num % 10);
}

int	get_max_num_of_digits(t_stack *stack)
{
	int	i;
	int	current;
	int	new;

	i = 0;
	current = 0;
	new = INT_MIN;
	while (i < stack->size)
	{
		current = ft_abs(stack->data[i]);
		if (current > new)
			new = current;
		i++;
	}
	i = 0;
	while (new != 0)
	{
		new = new / 10;
		i++;
	}
	return (i);
}

int	digit_is_checked(t_stack *stack, int pos, int digit)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (get_num_at_pos(stack->data[i], pos) == digit)
			return (0);
		i++;
	}
	return (1);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;
	while (i > 0)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	//int	max_digits;

	i = 0;
	//max_digits = get_max_num_of_digits(stack_a);
	//printf("max digits: %d\n", max_digits);
	while (!is_stack_ordered(stack_a))
	{
		sort_by_num_position(stack_a, stack_b, i++);
		print_stack("A", stack_a);
		print_stack("B", stack_b);
		rev_sort_num_by_pos(stack_a, stack_b, i++);
		print_stack("A", stack_a);
		print_stack("B", stack_b);
	}
	//printf("negatives");
	//sort_negatives(stack_a, stack_b);
	//merge_negatives(stack_a, stack_b);
}
