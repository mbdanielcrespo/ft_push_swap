#ifndef ALLOWED_FUNCTIONS_H
#define ALLOWED_FUNCTIONS_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./printf_42/ft_printf.h"

typedef struct s_stack
{
    int size;
    int *data;
} t_stack;

// Function prototypes
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack_a, t_stack *stack_b);

void shift_stack_up(t_stack *stack);
void shift_stack_down(t_stack *stack);

void print_stack(const char *stack_name, const t_stack *stack);

void turk_sort(t_stack *stack_a, t_stack *stack_b);

#endif