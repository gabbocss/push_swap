#include "libft.h"
#include "push_swap.h"

int numero_movimientos_num(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int i;

    i = 1;

    conteo->pos_num = 1;
    while (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
        pb(stack_a, stack_b, conteo);
    while (stack_a[0] > stack_b[i] && stack_a[0] < stack_b[i -1] && i < conteo->size_b)
        i++;
    if (i > conteo->size_b /2)
    {
		i = conteo->size_b -i;
		conteo->pos_num = 2;
    }
    return (i);
}

void	mover_num(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (!(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
	{
		if (conteo->pos_num == 1)
			rb(stack_b, conteo->size_b);
		if (conteo->pos_num == 2)
			rrb(stack_b, conteo->size_b);
	}
	pb(stack_a, stack_b, conteo);
}