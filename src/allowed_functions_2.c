/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:50 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:25:23 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	printf("rb\n");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
	return (0);
}

int	rra(t_list **stack_a)
{
	if (r_rotate(stack_a) == -1)
		return (-1);
	printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (r_rotate(stack_b) == -1)
		return (-1);
	printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	r_rotate(stack_a);
	r_rotate(stack_b);
	printf("rrr\n");
	return (0);
}
