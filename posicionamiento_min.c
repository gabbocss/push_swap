#include "libft.h"

void	posicionamiento_rr_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_min && conteo->num_min < stack_b[0])
	{
		rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
	}
	while (stack_a[0] != conteo->num_min && conteo->num_min <stack_b[0])
	{
		if (stack_a[0] != conteo->num_min)
			ra(stack_a, conteo->size_a);
		if (conteo->num_min < stack_b[0])
			rb(stack_b, conteo->size_b);
	}
	pb(stack_a, stack_b, conteo);
}
void	posicionamiento_rrr_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_min || conteo->num_min < stack_b[0])
	{
		rrr(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_min && conteo->num_min <stack_b[0])
	{
		if (stack_a[0] != conteo->num_min)
			rra(stack_a, conteo->size_a);
		if (conteo->num_min < stack_b[0])
			rrb(stack_b, conteo->size_b);
	}
	pb(stack_a, stack_b, conteo);
}

void	posicionamiento_ra_rb_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (conteo->rra_min == 1 && conteo->rrb_min == 2)
	{
		while (conteo->num_min != stack_a[0] && conteo->num_min < stack_b[0])
			{
				if (conteo->num_min != stack_a[0])
					ra(stack_a, conteo->size_a);
				if (conteo->num_min < stack_b[0])
					rrb(stack_b, conteo->size_b);
			}
	}
	if (conteo->rra_min == 2 && conteo->rrb_min == 1)
	{
		while (conteo->num_min != stack_a[0] && conteo->num_min < stack_b[0])
			{
				if (conteo->num_min != stack_a[0])
					rra(stack_a, conteo->size_a);
				if (conteo->num_min < stack_b[0])
					rb(stack_b, conteo->size_b);
			}
	}
	pb(stack_a, stack_b, conteo);
}
void posicionamiento_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int min;
	ft_printf("posicionamiento_min\n");
	ft_printf("el numero minimo es %i\n", conteo->num_min);
	conteo->num_min = ft_numero_minimo(stack_a, conteo->size_a);
	if (conteo->rra_min == conteo->rrb_min)
		{
			if(conteo->rra_min == 1)
				posicionamiento_rr_min(stack_a, stack_b, conteo);
			if(conteo->rra_min == 2)
				posicionamiento_rrr_min(stack_a, stack_b, conteo);
		}
	else
		posicionamiento_ra_rb_min(stack_a, stack_b, conteo);
}
