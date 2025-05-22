#include "libft.h"
#include "push_swap.h"

int	check(int *stack_a, t_conteo *conteo)
{
	int	i;

	i = 0;
	while (i < conteo->size_a -1)
	{
		if (stack_a[i] > stack_a[i +1])
			return (0);
		i++;
	}
	return (1);
}

