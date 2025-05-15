#include "push_swap.h"
#include "libft.h"

int	check_limites_minimo(t_conteo *conteo, int *stack_b)
{
	int	i;

	i = 0;
	while (i < conteo->size_b)
	{
		if (stack_b[i] == conteo->num_min)
			return(1);
		i++;
	}
	return (0);
}

int	check_limites_maximo(t_conteo *conteo, int *stack_b)
{
	int	i;

	i = 0;
	while (i < conteo->size_b)
	{
		if (stack_b[i] == conteo->num_max_a)
			return(1);
		i++;
	}
	return (0);
}