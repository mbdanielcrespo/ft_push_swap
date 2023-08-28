/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:27:23 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 17:00:23 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(const char *str, int sign, int res, int i)
{
	if (sign == 1 && res > (INT_MAX - (str[i] - '0')) / 10)
		return (0);
	if (sign == -1 && res > (INT_MIN + (str[i] - '0')) / -10)
		return (0);
	return (1);
}

int	ft_mod_atoi(const char *str, int *value)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-') 
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0') 
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (!check_overflow(str, sign, res, i))
			return (0);
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	*value = res;
	return (1);
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		order_stack_size_3(stack_a);
	else if (stack_a->size == 4)
		order_stack_size_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		order_stack_size_5(stack_a, stack_b);
	else
	{
		while (!is_circularly_sorted(stack_a))
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
			order_next_num(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			order_next_num(stack_b, stack_a);
		}
		perform_rotations_a(stack_a, -rotations_to_sort(stack_a));
	}
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
			printf("Error\n");
			free_stacks(stack_a, stack_b);
			return (0);
		}
		stack_a->data[stack_a->size++] = value;
		i++;
	}
	if (has_duplicates(stack_a)) 
	{
		printf("Error\n");
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
		printf("Error\n");
		return (0);
	}
	if (!initialize_stacks(argc, argv, &stack_a, &stack_b))
		return (0);
	if (is_stack_ordered(&stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	turk_sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
