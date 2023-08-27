#ifndef ALLOWED_FUNCTIONS_H
#define ALLOWED_FUNCTIONS_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
///#include "./printf_42/ft_printf.h"

typedef struct s_stack
{
    int size;
    int *data;
} t_stack;

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

// utils stack
void init_stack(t_stack *stack, int max_size);
void free_stack(t_stack *stack) ;
void print_stack(const char *stack_name, const t_stack *stack);
int is_stack_ordered(t_stack *stack);

// utils stack order
int rotations_to_sort(t_stack *stack);
int is_circularly_sorted(t_stack *stack);

// utils
int ft_min(int a, int b);
int ft_max(int a, int b);
int ft_abs(int a);

// perform rotations
void perform_rotations_a(t_stack *stack, int rotations);
void perform_rotations_b(t_stack *stack, int rotations);
void perform_rotations_both(t_stack *stack_a, t_stack *stack_b, int rotations);

// calculate_ops
int calculate_r_both(int r_a, int r_b);
int	calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index);
int	calculate_ops(t_stack *stack_a, t_stack *stack_b, int index);

// main
void order_stack_size_3(t_stack *stack);
void order_next_num(t_stack *stack_a, t_stack *stack_b);
void turk_sort(t_stack *stack_a, t_stack *stack_b);

#endif