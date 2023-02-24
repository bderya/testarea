/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:56:24 by bderya            #+#    #+#             */
/*   Updated: 2023/02/23 12:52:29 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_number(t_list **stack, int data)
{
    t_list *temp;
    t_list *newNode = (t_list *)malloc(sizeof(t_list));
    newNode->nbr = data;
    newNode->next = NULL;
    if (*stack == NULL)
    {
        *stack = newNode;
        return;
    }
    temp = *stack;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}