#include "libft.h"

void	posicionamiento_rr(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_max && conteo->num_max < stack_b[0])
	{
		rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
	}
	while (stack_a[0] != conteo->num_max && conteo->num_max <stack_b[0])
	{
		if (stack_a[0] != conteo->num_max)
			ra(stack_a, conteo->size_a);
		if (conteo->num_max < stack_b[0])
			rb(stack_b, conteo->size_b);
	}
	pb(stack_a, stack_b, conteo);
}
void	posicionamiento_rrr(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_max || conteo->num_max < stack_b[0])
	{
		rrr(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_max && conteo->num_max <stack_b[0])
	{
		if (stack_a[0] != conteo->num_max)
			rra(stack_a, conteo->size_a);
		if (conteo->num_max < stack_b[0])
			rrb(stack_b, conteo->size_b);
	}
	pb(stack_a, stack_b, conteo);
}

void	posicionamiento_ra_rb(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (conteo->rra_max == 1 && conteo->rrb_max == 2)
	{
		while (conteo->num_max != stack_a[0] && conteo->num_max < stack_b[0])
			{
				if (conteo->num_max != stack_a[0])
					ra(stack_a, conteo->size_a);
				if (conteo->num_max < stack_b[0])
					rrb(stack_b, conteo->size_b);
			}
	}
	if (conteo->rra_max == 2 && conteo->rrb_max == 1)
	{
		while (conteo->num_max != stack_a[0] && conteo->num_max < stack_b[0])
			{
				if (conteo->num_max != stack_a[0])
					rra(stack_a, conteo->size_a);
				if (conteo->num_max < stack_b[0])
					rb(stack_b, conteo->size_b);
			}
	}
	pb(stack_a, stack_b, conteo);
}
void posicionamiento_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int min;

	conteo->num_max = ft_numero_maximo(stack_a, conteo->size_a);
	if (conteo->rra_max == conteo->rrb_max)
		{
			if(conteo->rra_max == 1)
				posicionamiento_rr(stack_a, stack_b, conteo);
			if(conteo->rra_max == 2)
				posicionamiento_rrr(stack_a, stack_b, conteo);
		}
        else
		posicionamiento_ra_rb(stack_a, stack_b, conteo);
}
