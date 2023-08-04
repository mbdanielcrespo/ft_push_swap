/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:50 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/04 20:34:34 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sa(t_stack *stack)
{
    if (stack->size > 1)
    {
        int tmp = stack->data[0];
        stack->data[0] = stack->data[1];
        stack->data[1] = tmp;
    }
}

void sb(t_stack *stack)
{
    if (stack->size > 1)
    {
        int tmp = stack->data[0];
        stack->data[0] = stack->data[1];
        stack->data[1] = tmp;
    }
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    int value;
    
    if (stack_b->size > 0)
    {
        value = stack_b->data[0];
        shift_stack_up(stack_b);
        shift_stack_down(stack_a);
        stack_a->data[0] = value;
    }
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (stack_a->size > 0)
    {
        value = stack_a->data[0];
        shift_stack_up(stack_a);
        shift_stack_down(stack_b);
        stack_b->data[0] = value;
    }
}

void shift_stack_up(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        stack->data[i] = stack->data[i + 1];
        i++;
    }
    stack->size--;
}

void shift_stack_down(t_stack *stack)
{
    int i;

    i = stack->size - 1;
    while (i >= 0)
    {
        stack->data[i + 1] = stack->data[i];
        i--;
    }
    stack->size++;
}

void ra(t_stack *stack)
{
    int i;
    int value;


    if (stack->size > 1)
    {
        value = stack->data[0];
        i = 0;
        while (i < stack->size - 1)
        {
            stack->data[i] = stack->data[i + 1];
            i++;
        }
        stack->data[stack->size - 1] = value;
    }

}

void rb(t_stack *stack)
{
    int i;
    int value;

    if (stack->size > 1)
    {
        value = stack->data[0];
        i = 0;
        while (i < stack->size - 1)
        {
            stack->data[i] = stack->data[i + 1];
            i++;
        }
        stack->data[stack->size - 1] = value;
    }

}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_stack *stack)
{
    int value;
    int i;

    if (stack->size > 1)
    {
        value = stack->data[stack->size - 1];
        i = stack->size - 1;
        while (i > 0)
        {
            stack->data[i] = stack->data[i - 1];
            i--;
        }
        stack->data[0] = value;
    }
}

void rrb(t_stack *stack)
{
    int value;
    int i;

    if (stack->size > 1)
    {
        value = stack->data[stack->size - 1];
        i = stack->size - 1;
        while (i > 0)
        {
            stack->data[i] = stack->data[i - 1];
            i--;
        }
        stack->data[0] = value;
    }
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
