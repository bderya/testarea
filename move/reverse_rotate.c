#include "../push_swap.h"

/*
Shift down all elements of stack a by 1.
The last element becomes the first one.
*/
void    reverse_rotate_a(t_list **stack_a, int flag)
{
    t_list	*tmp;

    if(ft_lstsize(*stack_a) < 2)
        return ;
	tmp = *stack_a;
	while(tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next->next = (*stack_a);
    (*stack_a) = tmp->next;
    tmp->next = NULL;
    if(!flag)
        write(1, "rra\n", 4);
}

/*
Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void    reverse_rotate_b(t_list **stack_b, int flag)
{
    t_list	*tmp;

    if(ft_lstsize(*stack_b) < 2)
        return ;
	tmp = *stack_b;
	while(tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next->next = (*stack_b);
    (*stack_b) = tmp->next;
    tmp->next = NULL;
    if(!flag)
        write(1, "rrb\n", 4);
}

void    reverse_rotate_ab(t_list **stack_a, t_list **stack_b, int flag)
{
    if(ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
        return ;
    reverse_rotate_a(stack_a, 1);
    reverse_rotate_b(stack_b, 1);
    if(!flag)
        write(1, "rra\n", 4);
}
