#include "libft.h"

void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int movimientos_min;
	int movimientos_max;

    movimientos_min = numero_movimientos_min(stack_a, stack_b, conteo);
    movimientos_max = numero_movimientos_max(stack_a, stack_b, conteo);

	if (movimientos_min < movimientos_max)
		posicionamiento_min(stack_a, stack_b, conteo);
	else
		posicionamiento_max(stack_a, stack_b, conteo);
}
int    numero_movimientos_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int min;
	int	a;
	int b;
	
	a = 0;
	b = 0;
	conteo->num_min = ft_numero_minimo(stack_a, conteo->size_a);
	a = movimientos_a_realizar_stack_a_min(stack_a, conteo);
	b = movimientos_a_realizar_stack_b_min(stack_b, conteo);
	if(conteo->rra_min != conteo->rrb_min)
		return (a + b);
	else
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}
int	movimientos_a_realizar_stack_a_min(int *stack, t_conteo *conteo)
{
	int n;
	
	n = 0;
	while (conteo->num_min != stack[n] && n < conteo->size_a)
		n++;
	if (n <= conteo->size_a / 2)
	{
		conteo->rra_min = 1;
		return(n);
	}
	else
	{
		conteo->rra_min = 2;
		n++;
		return(conteo->size_a - n);
	}
}

int movimientos_a_realizar_stack_b_min(int *stack_b, t_conteo *conteo)
{
	int	n;

	n = 0;
	while(conteo->num_min < stack_b[n])
		n++;
	if (n <= conteo->size_b / 2)
		{
			conteo->rrb_min = 1;
			return (n);
		}
	else
	{
		conteo->rrb_min = 2;
		return (conteo->size_b - n);
	}
}

int    numero_movimientos_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int max;
	int	a;
	int b;

	a = 0;
	b = 0;
	conteo->num_max = ft_numero_maximo(stack_a, conteo->size_a);
	a = movimientos_a_realizar_stack_a_max(stack_a, conteo);
	b = movimientos_a_realizar_stack_b_max(stack_b, conteo);
	if(conteo->rra_max != conteo->rrb_max)
		return (a + b);
	else
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}




