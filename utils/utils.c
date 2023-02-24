#include "../push_swap.h"

bool	ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool ft_isspace(char ch)
{
    if(ch == ' ')
        return (true);
    else 
        return (false);
}

void error_input(void)
{
    write(2, "Less than 2 number\nError\n", 25);
    exit(0);
}

int		ft_error(void)
{
    write(2, "Error\n", 6);
    return (1);
}
