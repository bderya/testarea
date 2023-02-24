/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:05:44 by bderya            #+#    #+#             */
/*   Updated: 2023/02/24 11:09:44 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;

    if (check_input(argc, argv, &stack_a) != true)
    {
        printf("False Haha\n");
        // error_and_free(&stack_a);
    }
    if (algoritma(&stack_a) == true)
        write(1,"Done\n",5);
    
    return (0);
}