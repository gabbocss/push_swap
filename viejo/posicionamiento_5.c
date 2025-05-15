#include "libft.h"
#include "push_swap.h"

void	mover_r_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (conteo->pos_max == 1)
	{
		while (stack_a[0] != conteo->num_max_a)
		{
			ra(stack_b, conteo->size_b);
			if (stack_a[0] > stack_b[0] 
				&& stack_a[0] < stack_b[conteo->size_b -1]
				&& stack_a[0] != conteo->num_max_a)
				pb(stack_a, stack_b, conteo);
		}
		while (!(conteo->num_max_a > stack_b[0]
			&& conteo->num_max_a < stack_b[conteo-> size_b -1]))
			rrb(stack_b, conteo->size_b);
	}
	else
		mover_r_min_2(stack_a, stack_b, conteo);
	pb(stack_a, stack_b, conteo);	
}

void	mover_r_max_2(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_max_a)
	{
		rra(stack_b, conteo->size_b);
		if (stack_a[0] > stack_b[0] 
			&& stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
		while (conteo->num_max_a > stack_b[0]
			&& conteo->num_max_a < stack_b[conteo-> size_b -1])
			rb(stack_b, conteo->size_b);
}