#include "push_swap.h"

void perform_rotations_a(t_stack *stack, int rotations)
{
    if (rotations >= 0)
    {
        while (rotations > 0)
        {
            ra(stack);
			printf("ra\n");
        	rotations--;
        }
    }
    else
    {
        while (rotations < 0)
        {
            rra(stack);
			printf("rra\n");
            rotations++;
        }
    }
}

void perform_rotations_b(t_stack *stack, int rotations)
{
    if (rotations >= 0)
    {
        while (rotations > 0)
        {
            rb(stack);
			printf("rb\n");
        	rotations--;
        }
    }
    else
    {
        while (rotations < 0)
        {
            rrb(stack);
			printf("rrb\n");
            rotations++;
        }
    }
}

void perform_rotations_both(t_stack *stack_a, t_stack *stack_b, int rotations)
{
    while (rotations > 0)
    {
        rr(stack_a, stack_b);
		printf("rr\n");
        rotations--;
    }
    while (rotations < 0)
    {
        rrr(stack_a, stack_b);
		printf("rrr\n");
        rotations++;
    }
}