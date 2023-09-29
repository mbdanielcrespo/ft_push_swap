/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:27:23 by danalmei          #+#    #+#             */
/*   Updated: 2023/09/09 18:30:06 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		value;
	int		i;

	init_stack(stack_a, argc - 1);
	init_stack(stack_b, argc - 1);
	i = 1;
	while (i < argc) 
	{
		if (!ft_mod_atoi(argv[i], &value)) 
		{
			write(2, "Error\n", 6);
			free_stacks(stack_a, stack_b);
			return (0);
		}
		stack_a->data[stack_a->size++] = value;
		i++;
	}
	if (has_duplicates(stack_a)) 
	{
		write(2, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		return (0);
	}
	return (1);
}

// Falta criar o simple sort

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!initialize_stacks(argc, argv, &stack_a, &stack_b))
		return (1);
	if (is_stack_ordered(&stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	/*if (simple_sort(&stack_a, &stack_b, ))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}*/
	radix_sort(&stack_a, &stack_b);
	print_stack("A", &stack_a);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
