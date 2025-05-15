#include "libft.h"
#include "push_swap.h"

void	copiar_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo)
{
	int	i;

	i = 0;
	while (i < conteo->size_a)
	{
		stack_temp[i] = stack_a[i];
		i++;
	}
}

void	ordenar_stack_temp(int *stack_temp, t_conteo *conteo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < conteo->size_a -1)
	{
		if (stack_temp[i +1] < stack_temp[i])
		{
			j = stack_temp[i];
			stack_temp[i] = stack_temp[i +1];
			stack_temp[i +1] = j;
			i = -1;
		}
		i++;
	}	
}
