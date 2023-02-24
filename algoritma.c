/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritma.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:13:42 by bderya            #+#    #+#             */
/*   Updated: 2023/02/24 14:25:28 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_counter(t_list **stack)
{
    t_list *temp;
    int counter;
    
    counter = 0;
    temp = (*stack);
    while(temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    if (counter == 1)
        write(2, "One number inside\n", 18);
    else if(counter == 2)
        write(2,"sa\n",3);
    return (counter);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}


int list_counter_algoritma(t_list **stack)
{
    t_list *temp;
    int counter;
    
    counter = 0;
    temp = (*stack);
    while(temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return (counter);
}


void sort_three_number(t_list **stack)
{
    t_list *temp;

    temp = (*stack);
    if (temp->next->nbr < temp->nbr)
    {
        if(temp->next->next->nbr < temp->nbr && temp->next->nbr > temp->next->next->nbr)
            rotate_a(stack, 0);
        else if(temp->next->nbr < temp->next->next->nbr)
            swap_a(stack, 0);
        else
        {
            rotate_a(stack, 0);
            swap_a(stack, 0);
        }
    }
    else if(temp->next->next->nbr < temp->nbr && temp->next->nbr > temp->next->next->nbr)
        reverse_rotate_a(stack, 0);
    else if(temp->next->next->nbr > temp->nbr && temp->next->next->nbr < temp->next->nbr)
    {
        swap_a(stack, 0);
        rotate_a(stack, 0);
    }
}

int chunk_decider(int count)
{
    int a;

    a = 0;
    if (count < 17)
        a = 2;
    else if (count < 101)
        a = 4;
    else if (count < 501)
        a = 8;
    else
        a = 14;
    return (a);
}

int divider(int chunk, int count)
{
    return ((count/chunk));
}

int modder(int chunk, int count)
{
    return ((chunk%count));
}

void sort_list(t_list *stack) 
{
    int swapped;
    long int temp;
    t_list *first_point;
    t_list *lptr;
    
    lptr = NULL;
    if (stack == NULL)
        return;
    while (1) 
    {
        swapped = 0;
        first_point = stack;
        while (first_point->next != lptr)
        {
            if (first_point->nbr > first_point->next->nbr)
            {
                temp = first_point->nbr;
                first_point->nbr = first_point->next->nbr;
                first_point->next->nbr = temp;
                swapped = 1;
            }
            first_point = first_point->next;
        }
        if (!swapped)
            break;
        lptr = first_point;
    }
}

int take_number(t_list **stack, int limiter, int passer)
{
    int u_limit;
    int h_limit;
    int number;
    t_list *list;
    
    list = (*stack);
    u_limit = -1;
    h_limit = limiter * passer;
    while (++u_limit < h_limit)
        list = list->next;
    number = list->nbr;
    return (number);
}

bool pusher_number(t_list **stack, int number)
{
    t_list *temp;

    temp = (*stack);
    if (temp->nbr < number)
        return (true);
    return (false);
}

bool swapper_big(t_list **stack)
{
    t_list *temp;

    temp = (*stack);
    if (temp->nbr < temp->next->nbr)
        return (true);
    return (false);
}

int return_optimal_index(int *index, int size)
{
    int i;
    int optimal;

    i = 0;
    optimal = index[i];
    while (index[i] != 0)
    {
        if (index[i] < (size / 2))
        {
            if (optimal > index[i])
                optimal = index[i];
        }
        else
        {
            if(optimal > (size-index[i] + 2))
                optimal = index[i];
        }
        i++;
    }
    return(optimal);
}

/*
Number our stopper if smaller than number it will save to our index, 
*/
int smallest_move_finder(t_list **stack, int number, int limiter, int sizeof_stack)
{
    t_list *temp;
    int counter;
    int *index;
    int index_n;
    
    index_n = 0;
    counter = 1;
    temp = (*stack);
    index = (int *)malloc(sizeof_stack * sizeof(int));
    while(temp != NULL)
    {
        if (temp->nbr <= number)
        {
            index[index_n] = counter;
            index_n++;
        }
        temp = temp->next;
        counter++;
    }
    while (index_n < counter)
        index[index_n++] = 0;
    counter = return_optimal_index(index, list_counter_algoritma(stack));
    limiter = limiter + 1;
    return (counter);
}

void printList(t_list* head) {
    printf("List: ");
    t_list* current = head;
    while (current != NULL) {
        printf("%ld ", current->nbr);
        current = current->next;
    }
    printf("\n");
}


void algo_head(t_list **stack_a, t_list **stack_b, int number_move)
{
    int counter;
    t_list *temp;
    
    temp = NULL;
    counter = 0;
    
    if((*stack_b) != NULL)
    {
        temp = (*stack_b);
        temp = ft_lstlast(temp);
    }
    while(counter < number_move)
    {
        if (number_move == 1)
        {
            
            if ( stack_b != NULL)
            {
                //dprintf(2,"Here\n");
                swap_ab(stack_a, stack_b, 0);
            }
            else
            {
                dprintf(2,"Here\n");
                swap_a(stack_a,0);
            }
        }
        else if (temp->nbr > (*stack_b)->nbr && temp != NULL)
            rotate_ab(stack_a,stack_b,0);
        else
            rotate_a(stack_a, 0);
        counter++;
    }
    push_to_b(stack_a, stack_b, 0);
    temp = (*stack_b);
    printList(temp);
    printList(*stack_a);

}

void algo_back(t_list **stack_a, t_list **stack_b, int number_move)
{
    int counter;
    t_list *temp;
    
    temp = NULL;
    if((*stack_b) != NULL)
    {
        temp = (*stack_b);
        temp = ft_lstlast(temp);
    }
    counter = 0;
    while(counter < number_move)
    {
        if (temp->nbr > (*stack_b)->nbr && temp != NULL)
            reverse_rotate_ab(stack_a, stack_b, 0);
        else
            reverse_rotate_a(stack_a, 0);
        counter++;
    }
    push_to_b(stack_a, stack_b, 0);
}

/*
    sending somepart number to b
*/
void action(t_list **stack_a, t_list **stack_b, long int number ,int chunk_size)
{
    int counter;
    int counter2;
    int index;
    
    counter = 0;
    counter2 = 0;
    while(counter < chunk_size)
    {
        counter2 = ft_lstsize(*stack_a);
        index = smallest_move_finder(stack_a, number, chunk_size, (chunk_size - counter));
        dprintf(2,"Number of %d\n", index);
        if (index < ((counter2 + 1)/ 2) || ( counter2 < 5))
            algo_head(stack_a, stack_b, index);
        else
            algo_back(stack_a, stack_b, ((counter2 + 2) - index));
        counter = ft_lstsize(*stack_b);
    }
}
int smallest_number_index(t_list **stack)
{
    t_list *temp;
    int index;
    int counter;
    int number;
    
    counter = 1;
    index = 1;
    temp = (*stack);
    number = temp->nbr; 
    while (temp != NULL)
    {
        if (number > temp->nbr)
        {
            number = temp->nbr;
            index = counter;
        }
        counter++;
    }
    return (index);    
}

void action2(t_list **stack_a, t_list **stack_b)
{
    int counter;
    int index;
    int stack_size;
    
    index = 0;
    counter = 0;
    while(counter != 1)
    {
        stack_size = list_counter_algoritma(stack_a);
        if (stack_size <= 3)
        {
            sort_three_number(stack_a);
            counter = 1;
        }
        else
        {
            index = smallest_number_index(stack_a);
            if (index <= ((stack_size + 1)/ 2))
                algo_head(stack_a, stack_b, index - 1);
            else
                algo_back(stack_a, stack_b, ((stack_size + 1) - index));
        }
    }
}
t_list *copyList(t_list *head)
{
    if (head == NULL) {
        return NULL;
    }

    // Create a new head node
    t_list *newHead = (t_list *)malloc(sizeof(t_list));
    newHead->nbr = head->nbr;
    newHead->next = NULL;

    // Traverse the original list and copy each node
    t_list *curr = head->next;
    t_list *prev = newHead;
    while (curr != NULL) {
        t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->nbr = curr->nbr;
        newNode->next = NULL;
        prev->next = newNode;
        prev = newNode;
        curr = curr->next;
    }

    return newHead;
}

/*
    passer is controlling chunk for short (Which one we need to take)
    number numaradan kucuk sayilari bye gonderir
    decider is find to which number should be taking to base for algoritma
*/
t_list *first_sort(t_list **stack_a, t_list **stack_b, int chunk, int one_chunk_size)
{
    t_list *decider;
    int count;
    int passer;
    long int number;
    
    passer = 1;
    count = list_counter_algoritma(stack_a);
    decider = copyList(*stack_a);
    sort_list(decider);
    dprintf(2," Decider list:\n");
    printList(decider);
    while (passer < chunk)
    {
        number = take_number(&decider, one_chunk_size, passer);
        dprintf(2,"Taking Number is %ld\n",number);
        action(stack_a, stack_b, number, (one_chunk_size * passer));
        passer++;
    }
    dprintf(2," ----------:\n");
    number = take_number(&decider, ((one_chunk_size / 8) * 7), passer);
    action(stack_a, stack_b, number, ((one_chunk_size / 8) * 7 ));
    action2(stack_a, stack_b);
    return (*stack_b);
}

int biggest_number_index(t_list **stack)
{
    t_list *temp;
    int index;
    int counter;
    int number;
    
    counter = 1;
    index = 1;
    temp = (*stack);
    number = temp->nbr; 
    while (temp != NULL)
    {
        if (number < temp->nbr)
        {
            number = temp->nbr;
            index = counter;
        }
        counter++;
    }
    return (index);    
}

void algo_head_a(t_list **stack_a, t_list **stack_b, int number_move)
{
    int counter;
    
    counter = 0;
    while(counter < number_move)
    {
        if (number_move == 1)
            swap_b(stack_b,0);
        else
            rotate_b(stack_b,0);
        counter++;
    }
    push_to_a(stack_a, stack_b, 0);
}

void algo_back_a(t_list **stack_a, t_list **stack_b, int number_move)
{
    int counter;

    counter = 0;
    while(counter < number_move)
    {
        reverse_rotate_b(stack_b, 0);
        counter++;
    }
    push_to_b(stack_a, stack_b, 0);
}

t_list *last_sort(t_list **stack_a, t_list **stack_b)
{
    int stack_size;
    int index;

    index = 0;
    stack_size = 1;
    while(stack_size != 0)
    {
        stack_size = list_counter_algoritma(stack_b);
        if (stack_size != 0)
        {
            index = biggest_number_index(stack_b);
            if (index <= ((stack_size + 1)/ 2))
                algo_head_a(stack_a, stack_b, index - 1);
            else
                algo_back_a(stack_a, stack_b, ((stack_size + 1) - index));
        }
    }

    return (*stack_a);
}

/*
    Chunk is how much we need to dive for shorthing
    one_chunk_size is how much number shorting in one chunk
*/
void sorthing(t_list **stack_a, int count)
{
    t_list *stack_b;
    int chunk;
    int one_chunk_size;

    stack_b = NULL;
    chunk = chunk_decider(count);
    if (modder(chunk,count) != 0)
        one_chunk_size = divider(chunk, count) + 1;
    else
        one_chunk_size = divider(chunk, count);
    dprintf(2,"Stack A\n");
    printList(*stack_a);
    stack_b = first_sort(stack_a, &stack_b, chunk, one_chunk_size);
    (*stack_a) = last_sort(stack_a, &stack_b);
    
}


bool algoritma(t_list **stack)
{
    int count;

    count = list_counter(stack);
    if (count <= 3)
    {
        if (count == 3)
            sort_three_number(stack);
        return (true);
    }
    else
        sorthing(stack, count);
        
    return (true);
}
