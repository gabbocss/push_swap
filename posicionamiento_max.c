#include "libft.h"
#include "push_swap.h"

void	posicionamiento_rr(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_max_a && conteo->num_max_a < stack_b[0])
	{
		rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
	}
	while (stack_a[0] != conteo->num_max_a || !(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
	{
		
		if (stack_a[0] != conteo->num_max_a)
			ra(stack_a, conteo->size_a);
		if (!(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
			rb(stack_b, conteo->size_b);
	}
	/*if (conteo->size_b > 1)
	{
		while (stack_a[0] > stack_b[conteo->size_b -1])
		{
			ft_printf("posicionamiento_rr\n");
			rrb(stack_b, conteo->size_b);
			ft_printf("stack_a[0] == %i\n", stack_a[0]);
			ft_printf("conteo->size_b == %i\nconteo->size_a == %i\n", conteo->size_b, conteo->size_a);
			ft_printf("stack_b[0] == %i\nsgack_b[1] == %i\n", stack_b[0], stack_b[1]);
			
		}
	}*/
           
    //ft_printf("1\n");
	pb(stack_a, stack_b, conteo);
}
void	posicionamiento_rrr(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] != conteo->num_max_a && conteo->num_max_a < stack_b[0])
	{
		rrr(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_max_a || conteo->num_max_a <stack_b[0])
	{
		if (stack_a[0] != conteo->num_max_a)
			rra(stack_a, conteo->size_a);
		if (conteo->num_max_a < stack_b[0])
			rrb(stack_b, conteo->size_b);
	}
    //ft_printf("2\n");
	pb(stack_a, stack_b, conteo);
}

void	posicionamiento_ra_rb(int *stack_a, int *stack_b, t_conteo *conteo)
{
if (conteo->rra_max == 1 && conteo->rrb_max == 2)
{
	
	while (conteo->num_max_a != stack_a[0] || !(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
	{
		
		if (conteo->num_max_a != stack_a[0])
			ra(stack_a, conteo->size_a);

		if (!(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
			rrb(stack_b, conteo->size_b);
	}
}

	if (conteo->rra_max == 2 && conteo->rrb_max == 1)
	{
		
		while (conteo->num_max_a != stack_a[0] || !(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
			{
				if (conteo->num_max_a != stack_a[0])
					rra(stack_a, conteo->size_a);
				if (!(stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]))
					rb(stack_b, conteo->size_b);
			}
	}
    //ft_printf("3\n");
	pb(stack_a, stack_b, conteo);
}
void posicionamiento_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int min;
    //ft_printf("posicionando max\n");
	conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
    /*if (conteo->size_b == 1 && conteo->num_max > stack_b[0])
        conteo->rra_max = 2;
    if (conteo->size_b == 1 && conteo->num_max < stack_b[0])
        conteo->rra_max = 1;*/

	
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
