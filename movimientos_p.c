#include "libft.h"
#include "push_swap.h"

void	espacio_pa_pb(int *stack, int size)
{
	int n;

	n = size -1;
	if (size <= 1)
		return;
	while (n >= 1)
	{
		stack[n] = stack[n -1];
		n--;
	}
}
void recolocacion_stack(int *stack, int size)
{
	int n;

	n = 0;
	if (size == 0)
		return;
	while(n < size -1)
	{
		stack[n] = stack[n +1];
		n++;
	}
}

void	pa(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (conteo->size_b == 0)
		return;
	conteo->size_a++;
	espacio_pa_pb(stack_a, conteo->size_a);
	stack_a[0] = stack_b[0];
	if (conteo->size_b >= 1)
		recolocacion_stack(stack_b, conteo->size_b);
	conteo->size_b--;
	ft_printf("pa\n");
}

void	pb(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (conteo->size_a == 0)
		return;
	conteo->size_b++;
	espacio_pa_pb(stack_b, conteo->size_b);
	stack_b[0] = stack_a[0];
	if (conteo->size_a >= 1)
		recolocacion_stack(stack_a, conteo->size_a);
	conteo->size_a--;
	if (conteo->size_b == 2 && stack_b[0] < stack_b[1])
		sb(stack_b, conteo->size_b);
	ft_printf("pb\n");
}

