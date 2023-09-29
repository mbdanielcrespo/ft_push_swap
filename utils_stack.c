/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:25:54 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:04:39 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int max_size)
{
	stack->data = (int *)malloc((max_size + 1) * sizeof(int));
	stack->size = 0;
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

void	print_stack(const char *stack_name, const t_stack *stack)
{
	int	i;

	i = 0;
	printf("%s Stack (size: %d): ", stack_name, stack->size);
	while (i < stack->size) 
	{
		printf("%d ", stack->data[i]);
		i++;
	}
	printf("\n");
}

int	is_stack_ordered(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1); 
}

