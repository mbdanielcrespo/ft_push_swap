/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:33:34 by danalmei          #+#    #+#             */
/*   Updated: 2023/09/09 16:35:29 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_of_min(t_stack *stk)
{
	int	min_val;
	int	min_index;
	int	i;

	min_val = stk->data[0];
	min_index = 0;
	i = 0;
	while (i < stk->size)
	{
		if (stk->data[i] < min_val)
		{
			min_val = stk->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	order_stack_size_3(t_stack *stk)
{
	while (!(stk->data[0] < stk->data[1] && stk->data[1] < stk->data[2]))
	{
		if (stk->data[0] > stk->data[1] && stk->data[0] < stk->data[2])
			sa(stk);
		else if (stk->data[1] > stk->data[0] && stk->data[1] > stk->data[2])
			rra(stk);
		else if (stk->data[0] > stk->data[1] && stk->data[0] > stk->data[2])
			ra(stk);
	}
}

void	order_stack_size_4(t_stack *stk, t_stack *stk_b)
{
	int	min_index;

	while (!is_stack_ordered(stk))
	{
		min_index = ft_index_of_min(stk);
		if (min_index == 3)
		{
			pb(stk, stk_b);
			order_stack_size_3(stk);
			pa(stk, stk_b);
			return ;
		}
		else
		{
			if (min_index == 0)
				ra(stk);
			else if (min_index == 1)
				rra(stk);
			else if (min_index == 2)
				sa(stk);
		}
	}
}

void	order_stack_size_5(t_stack *stk, t_stack *stk_b)
{
	int	min_index;
	int	i;

	i = 0;
	while (i < 2) 
	{
		min_index = ft_index_of_min(stk);
		while (min_index != 0) 
		{
			if (min_index < 3)
				ra(stk);
			else
				rra(stk);
			min_index = ft_index_of_min(stk);
		}
		pb(stk, stk_b);
		++i;
	}
	order_stack_size_3(stk);
	pa(stk, stk_b);
	pa(stk, stk_b); 
}

int	simple_sort(t_stack *stack_a, t_stack *stack_b, int n_args)
{
	if (n_args <= 5)
	{
		if (n_args == 3)
			order_stack_size_3(stack_a);
		else if (n_args == 4)
			order_stack_size_4(stack_a, stack_b);
		else if (n_args == 5)
			order_stack_size_5(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}