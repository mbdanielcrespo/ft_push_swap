#include "push_swap.h"

int ft_min(int a, int b)
{
    if (b < a)
        return (b);
    else
    	return (a);
}

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}