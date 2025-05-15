#include "libft.h"
#include "push_swap.h"

void    mover_maximo(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int	k;

	k = 0;
	if ((conteo->num_max_a > stack_b[0] && conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		k = 1;
		while (!(stack_b[k] > conteo->num_max_a && stack_b[k -1] < conteo->num_max_a))
			k++;
	}
	if (conteo->pos_max == 1 && k <= conteo->size_b /2)
		mover_rr_max(stack_a, stack_b, conteo);
	else if (conteo->pos_max == 2 && k > conteo->size_b /2)
		mover_rrr_max(stack_a, stack_b, conteo);
	else
		mover_r_max(stack_a, stack_b, conteo);
}

void	mover_rr_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if ((stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	while (stack_a[0] != conteo->num_max_a && !(conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_max_a && (conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		ra(stack_a, conteo->size_a);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	mover_rr_max_2(stack_a, stack_b, conteo);
}

void	mover_rr_max_2(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] == conteo->num_max_a && !(conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		rb(stack_b, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	pb(stack_a, stack_b, conteo);
}

void	mover_rrr_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	while (stack_a[0] != conteo->num_max_a && !(conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		rrr(stack_a, stack_b, conteo);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_max_a && (conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		rra(stack_a, conteo->size_a);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	mover_rrr_max_2(stack_a, stack_b, conteo);
}

void	mover_rrr_max_2(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] == conteo->num_max_a && !(conteo->num_max_a > stack_b[0]
		&& conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		rrb(stack_b, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
	}
	pb(stack_a, stack_b, conteo);
}