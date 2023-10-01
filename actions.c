#include "push_swap.h"

int swap(t_list **stack) {
    t_list *head; 
    t_list *next;
    int tmp_val;
    int tmp_index;   

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
	next = head->next;
    if (!head && !next)
        ft_error("Error occurred while swapping!"); 
	tmp_val = head->value;
    tmp_index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = tmp_val;
    next->index = tmp_index;
    return (0);
}


int push(t_list **stack_to, t_list **stack_from) {
    t_list *tmp;
    t_list *head_to;
    t_list *head_from;

    if (ft_lstsize(*stack_from) == 0)
        return (-1);
    head_to = *stack_to;
    head_from = *stack_from;
    tmp = head_from;			// Move the top node from the source stack to the temporary pointer
    *stack_from = head_from->next;	// Update the source stack's head to point to the new top node
    if (!head_to)  	// If empty, make the destination stack's head point to the moved node
	{   
        head_to = tmp;
        head_to->next = NULL;
        *stack_to = head_to;
    } else 			// If not empty, attach the moved node to the destination stack
	{
        tmp->next = head_to;
        *stack_to = tmp;
    }
    return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int r_rotate(t_list **stack) {
    t_list *head;
	t_list *tail;
	
	if (ft_lstsize(*stack) < 2)
        return (-1);

    head = *stack;
    tail = ft_lstlast(head);

    tail->next = head;
    *stack = tail->next;
    head = tail->next;
    head->next = NULL;
    return (0);
}

