#include "push_swap.h"

int check_overflow(long long res)
{
    if (res > INT_MAX || res < INT_MIN)
        return (0);
    return (1);
}

int	ft_mod_atoi(const char *str, int *value)
{
	long long	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-') 
	{
		sign = -1;
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	while (str[i] != '\0') 
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0') * sign;
		if (!check_overflow(res))
			return (0);
		i++;
	}
	*value = (int)res;
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i; 
	int	j;

	i = 0;
	while (i < stack->size) 
	{
		j = i + 1;
		while (j < stack->size) 
		{
			if (stack->data[i] == stack->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}