/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:27:23 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/30 18:59:39 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_overflow(long long res)
{
    if (res > INT_MAX || res < INT_MIN)
        return (0);
    return (1);
}

int	ft_mod_atoi(const char *str, int *value)
{
	long long	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-') 
	{
		sign = -1;
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	while (str[i] != '\0') 
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0') * sign;
		if (!check_overflow(res))
			return (0);
		i++;
	}
	*value = (int)res;
	return (1);
}

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
		return (1);
	}
	print_stack("A", &stack_a);
	print_stack("B", &stack_b);
	turk_sort(&stack_a, &stack_b);
	print_stack("A", &stack_a);
	print_stack("B", &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
