#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct s_list
{
    long int    nbr;
    long int    index;
    struct s_list *next;
}	t_list;



void algo_head_a(t_list **stack_a, t_list **stack_b, int number_move);
void algo_head(t_list **stack_a, t_list **stack_b, int number_move);
/** Error hand **/
int ft_error(void);
void error_input(void);
bool algoritma(t_list **stack);
int list_counter_algoritma(t_list **stack);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

/** Utils for checking arg and parsing **/
/*Split*/
char        **ft_split(char const *s, char c);
//static int	split_separate(char **arr, const char *str, char c);
//static int	split_separate2(char **arr, const char *str, char c, size_t w);
//static char	*my_strncpy(char *dst, const char *src, size_t len);

/*Controller for check_argument_value*/
bool        word_counter(char *str);
bool        check_space(char *arguments);
bool	    ft_isdigit(int c);
bool        ft_isspace(char ch);
int	        ft_atoi(const char *str);

/** Checker for argument**/
bool check_input(int argc, char **argv, t_list **stack);
bool check_duplicate(t_list **stack, int argc, char **argv, int i);
bool check_duplicate_2(t_list **stack);
bool check_argument_value(char *arguments);

/** Parsing function **/
void add_number(t_list **stack, int data);

/** Move command **/
/* SWAP && sa - sb - ss */
void	swap_a(t_list **stack_a, int flag);
void	swap_b(t_list **stack_b, int flag);
void	swap_ab(t_list **stack_a, t_list **stack_b, int flag);

/* PUSH && pa - pb */
void	push_to_a(t_list **stack_a, t_list **stack_b, int flag);
void    push_to_b(t_list **stack_a, t_list **stack_b, int flag);

/* ROTATE && ra - rb - rr */
void	rotate_a(t_list **stack_a, int flag);
void	rotate_b(t_list **stack_b, int flag);
void	rotate_ab(t_list **stack_a, t_list **stack_b, int flag);

/* REVERSE ROTATE && rra - rrb - rrr */
void    reverse_rotate_a(t_list **stack_a, int flag);
void    reverse_rotate_b(t_list **stack_b, int flag);
void    reverse_rotate_ab(t_list **stack_a, t_list **stack_b, int flag);

#endif