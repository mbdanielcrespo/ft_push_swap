/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:07:51 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/25 13:08:32 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*top;
	t_list	*next;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_error("Error while swapping!");
	ft_swap(&top->value, &next->value);
	ft_swap(&top->index, &next->index);
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*top_to;
	t_list	*top_from;

	if (ft_lstsize(*stack_from) == 0)
		ft_error("Error while pushing!");
	top_to = *stack_to;
	top_from = *stack_from;
	tmp = top_from;
	top_from = top_from->next;
	*stack_from = top_from;
	if (!top_to)
	{
		top_to = tmp;
		top_to->next = NULL;
		*stack_to = top_to;
	}
	else
	{
		tmp->next = top_to;
		*stack_to = tmp;
	}
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	if (ft_lstsize(*stack) < 2)
		ft_error("Error while rotating!");
	top = *stack;
	bottom = ft_lstlast(top);
	*stack = top->next;
	top->next = NULL;
	bottom->next = top;
	return (0);
}

int	r_rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	if (ft_lstsize(*stack) < 2)
		ft_error("Error while r_rotating!");
	top = *stack;
	bottom = ft_lstlast(top);
	while (top)
	{
		if (!top->next->next)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bottom->next = *stack;
	*stack = bottom;
	return (0);
}
