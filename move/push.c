#include "../push_swap.h"

	/*
		from:
		STACK A			STACK B
		STACK A->next	STACK B->next
		...				...

		to:
		STACK B       	STACK B->next     
		STACK A			...
		...
	*/
void	push_to_a(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list  *tmp;

	if(!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_b) = tmp;

	if (!flag)
		write(1, "pa\n", 3);

}

/*
		from:
		STACK B			STACK A
		STACK B->next	STACK A->next
		...				...

		to:
		STACK A       	STACK A->next     
		STACK B			...
		...
	*/
void    push_to_b(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list  *tmp;

	if(!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_a) = tmp;
	if (!flag)
		write(1, "pb\n", 3);
}
