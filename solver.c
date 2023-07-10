#include <stdbool.h>
#include "solver.h"

#include <stdbool.h>
#include "solver.h"

void merge_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return;

    t_stack stack_a_half1;
    t_stack stack_a_half2;
    t_stack stack_b_half1;
    t_stack stack_b_half2;

    split_stack(stack_a, &stack_a_half1, &stack_a_half2);
    merge_sort(&stack_a_half1, &stack_b_half1);
    merge_sort(&stack_a_half2, &stack_b_half2);
    merge(stack_a, &stack_a_half1, &stack_a_half2, &stack_b_half1, &stack_b_half2);
    merge_remaining(stack_a, &stack_b_half1);
    merge_remaining(stack_a, &stack_b_half2);
}

void split_stack(t_stack *stack, t_stack *stack_half1, t_stack *stack_half2)
{
    int stack_size = stack->size;
    int half1_size = stack_size / 2;
    int half2_size = stack_size - half1_size;

    stack_half1->size = half1_size;
    stack_half1->data = stack->data;

    stack_half2->size = half2_size;
    stack_half2->data = stack->data + half1_size;
}

void merge(t_stack *stack_a, t_stack *stack_a_half1, t_stack *stack_a_half2,
           t_stack *stack_b_half1, t_stack *stack_b_half2)
{
    while (stack_a_half1->size > 0 && stack_a_half2->size > 0)
    {
        if (stack_a_half1->data[0] < stack_a_half2->data[0])
            pa(stack_a, stack_b_half1);
        else
            pa(stack_a, stack_b_half2);
    }

    while (stack_a_half1->size > 0)
        pa(stack_a, stack_b_half1);
    while (stack_a_half2->size > 0)
        pa(stack_a, stack_b_half2);
}

void merge_remaining(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}
