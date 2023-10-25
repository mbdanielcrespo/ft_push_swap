/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:25:45 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/25 13:09:20 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_distance(t_list **stack, int index)
{
	t_list	*top;
	int		distance;

	distance = 0;
	top = *stack;
	while (top)
	{
		if (top->index == index)
			break ;
		distance++;
		top = top->next;
	}
	return (distance);
}

int	get_min(t_list **stack, int val)
{
	t_list	*top;
	int		min;

	top = *stack;
	min = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min) && top->index != val)
			min = top->index;
	}
	return (min);
}

t_list	*get_next_min(t_list **stack)
{
	t_list	*top;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	top = *stack;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!has_min || top->value < min->value))
			{
				min = top;
				has_min = 1;
			}
			top = top->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*top;
	int		index;

	index = 0;
	top = get_next_min(stack);
	while (top)
	{
		top->index = index++;
		top = get_next_min(stack);
	}
}
