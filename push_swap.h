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

int ft_min(int a, int b);
int ft_max(int a, int b);
int ft_abs(int a);

void perform_rotations_a(t_stack *stack, int rotations);
void perform_rotations_b(t_stack *stack, int rotations);
void perform_rotations_both(t_stack *stack_a, t_stack *stack_b, int rotations);

int calculate_rotations_to_top(t_stack *stack, int target_index);
int calculate_r_both(int r_a, int r_b);
int	calculate_ops(t_stack *stack_a, t_stack *stack_b, int index);
int	calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index);

void turk_sort(t_stack *stack_a, t_stack *stack_b);

#endif