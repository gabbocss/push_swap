#include "libft.h"

int	movimientos_a_realizar_stack_a_max(int *stack_a, t_conteo *conteo)
{
	int n;
	
	n = 0;
	while (conteo->num_max != stack_a[n] && n < conteo->size_a)
		n++;
	if (n <= conteo->size_a / 2)
	{
		conteo->rra_max = 1;
		return(n);
	}
	else
	{
		conteo->rra_max = 2;
		n++;
		return(conteo->size_a - n);
	}
}

int movimientos_a_realizar_stack_b_max(int *stack_b, t_conteo *conteo)
{
	int	n;

	n = 0;
	while(conteo->num_max < stack_b[n])
		n++;
	if (n <= conteo->size_b / 2)
		{
			conteo->rrb_max = 1;
			return (n);
		}
	else
	{
		conteo->rrb_max = 2;
		return (conteo->size_b - n);
	}
}