#include "../push_swap.h"

bool word_counter(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i == 0 || (str[0] == 32 &&  (str[i] == 27 || str[i] == 32)))
		return(false);
	return (true);
}
