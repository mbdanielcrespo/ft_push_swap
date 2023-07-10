
#include "push_swap.h"

void ra(t_stack *stack)
{
    int first_element;
    int i;


    if (stack->size > 1)
    {
        first_element = stack->data[0];
        i = 0;
        while (i < stack->size - 1)
        {
            stack->data[i] = stack->data[i + 1];
            i++;
        }
        stack->data[stack->size - 1] = first_element;
    }
}

void rb(t_stack *stack)
{
    int first_element;
    int i;

    
    if (stack->size > 1)
    {
        first_element = stack->data[0];
        i = 0;
        while (i < stack->size - 1)
        {
            stack->data[i] = stack->data[i + 1];
            i++;
        }
        stack->data[stack->size - 1] = first_element;
    }
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_stack *stack)
{
    int last_element;
    int i;

    if (stack->size > 1)
    {
        last_element = stack->data[stack->size - 1];
        i = stack->size - 1;
        while (i > 0)
        {
            stack->data[i] = stack->data[i - 1];
            i--;
        }
        stack->data[0] = last_element;
    }
}

void rrb(t_stack *stack)
{
    int last_element;
    int i;

    if (stack->size > 1)
    {
        last_element = stack->data[stack->size - 1];
        i = stack->size - 1;
        while (i > 0)
        {
            stack->data[i] = stack->data[i - 1];
            i--;
        }
        stack->data[0] = last_element;
    }
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}