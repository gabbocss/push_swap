#include "libft.h"
#include "push_swap.h"

void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	i;
	int	movimientos_max;

	movimientos_max = -1;
	i = 1;
	if (conteo->size_a == 0)
		return;
	control_jugadas_0(stack_a[0], stack_b, conteo, i);
	while (i < conteo->size_a)
	{
		if (stack_a[i] != conteo->num_max_a)
			control_jugadas(stack_a[i], stack_b, conteo, i);
		else
			movimientos_max = numero_movimientos_max(stack_a, stack_b, conteo);
		i++;
	}
	if (movimientos_max != -1)
	{
		if (movimientos_max < conteo->movimientos)
			{
				pasar_max(stack_a, stack_b, conteo);
			}
	}
	posicionamiento_mejor_opcion(stack_a, stack_b, conteo);

}

void pasar_max(int *stack_a, int * stack_b, t_conteo *conteo)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	conteo->num_max_b = ft_numero_maximo(stack_b, conteo->size_b);
	while (stack_a[a] != conteo->num_max_a)
		a++;
	while (stack_b[b] != conteo->num_max_b)
		b++;
	if (a <= conteo->size_a / 2 && b <= conteo->size_b / 2)
	{
		while (stack_a[0] != conteo->num_max_a && stack_b[0] != conteo->num_max_b)
				rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
		while (stack_a[0] != conteo->num_max_a || stack_b[0] != conteo->num_max_b)
			{
		
				if (stack_a[0] != conteo->mejor_opcion)
					ra(stack_a, conteo->size_a);
				if (stack_b[0] != conteo->num_max_b)
					rb(stack_b, conteo->size_b);
			}
	}
	if (a > conteo->size_a / 2 && b > conteo->size_b / 2)
	{
		while (stack_a[0] != conteo->num_max_a && stack_b[0] != conteo->num_max_b)
				rrr(stack_a, stack_b, conteo);
		while (stack_a[0] != conteo->num_max_a || stack_b[0] != conteo->num_max_b)
			{
				
				if (stack_a[0] != conteo->mejor_opcion)
					rra(stack_a, conteo->size_a);
				if (stack_b[0] != conteo->num_max_b){
					//ft_printf("aqui");
					rrb(stack_b, conteo->size_b);}
			}
	}
	if (a > conteo->size_a / 2 && b <= conteo->size_b / 2)
	{
		while (stack_a[0] != conteo->num_max_a || stack_b[0] != conteo->num_max_b)
			{
				if (stack_a[0] != conteo->mejor_opcion)
					rra(stack_a, conteo->size_a);
				if (stack_b[0] != conteo->num_max_b)
					rb(stack_b, conteo->size_b);
			}
	}

	else
	{
		while (stack_a[0] != conteo->num_max_a || stack_b[0] != conteo->num_max_b)
			{
				//ft_printf("se empieza\n");
				if (stack_a[0] != conteo->num_max_a)
					ra(stack_a, conteo->size_a);
				if (stack_b[0] != conteo->num_max_b)
				{
					//ft_printf("aqui\nconteo->num_max_a == %i\nconteo->num_max_b == %i\nstack_b[0] == %i\nstack_a[0] == %i", conteo->num_max_a, conteo->num_max_b, stack_b[0], stack_a[0]);
					rrb(stack_b, conteo->size_b);
				}
					
			}
	}

	pb(stack_a, stack_b, conteo);
}
void	posicionamiento_mejor_opcion(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	conteo->rra_min = 0;
	conteo->rrb_min = 0;
	while (stack_a[i] != conteo->mejor_opcion)
		i++;
	if (i <= conteo->size_a /2)
		conteo->rra_min = 1;
	else 
		conteo->rra_min = 2;
	while (j < conteo->size_b -1)
	{
		if (conteo->mejor_opcion > stack_b[j] && conteo->mejor_opcion < stack_b[j -1])
		{
			conteo->rrb_min = 3;
			break;
		}
		j++;
	}
	if (conteo->rrb_min == 3 && j <= conteo->size_b /2)
		conteo->rrb_min = 1;
	if ((conteo->rrb_min == 3 && j > conteo->size_b /2) || conteo->rrb_min == 0)
		conteo->rrb_min = 2;
	if (conteo->rra_min == 1 && conteo->rrb_min == 1)
		{
			while (stack_a[0] != conteo->mejor_opcion && !(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
				rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
			while (stack_a[0] != conteo->mejor_opcion || !(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
				{
					
					if (stack_a[0] != conteo->mejor_opcion)
						ra(stack_a, conteo->size_a);
					if (!(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
						rb(stack_b, conteo->size_b);
				}
		}
	if (conteo->rra_min == 2 && conteo->rrb_min == 2)
	{
		while (stack_a[0] != conteo->mejor_opcion && !(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
				rrr(stack_a, stack_b, conteo);
		while (stack_a[0] != conteo->mejor_opcion || !(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
			{
				
				//ft_printf("aqui estoy");
				if (stack_a[0] != conteo->mejor_opcion)
					rra(stack_a, conteo->size_a);
				if (!(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
					rrb(stack_b, conteo->size_b);
			}
	}
	if (conteo->rra_min != conteo->rrb_min)
	{
		if (conteo->rra_min == 1)
		
			while (stack_a[0] != conteo->mejor_opcion){
				
				ra(stack_a, conteo->size_a);
			}
		else 
			while(stack_a[0] != conteo->mejor_opcion)
				rra(stack_a, conteo->size_a);
		if (conteo->rrb_min == 1)
			while (!(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1])){
				rb(stack_b, conteo->size_b);
			}
		else 
			while(!(conteo->mejor_opcion > stack_b[0] && conteo->mejor_opcion < stack_b[conteo->size_b -1]))
			{
				//ft_printf("aqui es\nconteo->size_a == %i\nconteo->size_b == %i", conteo->size_a, conteo->size_b);
				rrb(stack_b, conteo->size_b);
		// 			i = 0;
		// ft_printf("\nstack_a[0] == %i\nstack_a[1] == %i\nstack_a[2] == %i\n", stack_a[0], stack_a[1],stack_a[2]);
		// while(i < conteo->size_b)
		// {
		// 	ft_printf("stack_b[%i] == %i\n", i, stack_b[i]);
		// 	i++;
		// }
			}
				
	}
	//ft_printf("conteo->size_b == %i\nconteo->rra_min == %i\nconteo->rrb_min == %i", conteo->size_b, conteo->rra_min, conteo->rrb_min);

	
	pb(stack_a, stack_b, conteo);
}
void	control_jugadas_0(int numero_stack, int *stack_b, t_conteo *conteo, int i)
{
	int	movimientos;
	int	j;

	j = 0;
	movimientos = 0;
	if (i <= conteo->size_a /2)
		movimientos = i;
	else
		movimientos = conteo->size_a - i;
	if (numero_stack > stack_b[0] && numero_stack < stack_b[conteo->size_b -1])
	{
		conteo->movimientos = movimientos;
		conteo->mejor_opcion = numero_stack;
		return;
	}
	while (!(numero_stack > stack_b[j] && numero_stack < stack_b[j -1]))
		j++;
	if (j <= conteo->size_b /2)
		movimientos += j;
	else
		movimientos += (conteo->size_b - j);
	conteo->movimientos = movimientos;
	conteo->mejor_opcion = numero_stack;
}

void	control_jugadas(int numero_stack, int *stack_b, t_conteo *conteo, int i)
{
	//ft_printf("contro_jugadas");
	int	movimientos;
	int	j;

	j = 0;
	movimientos = 0;
	if (i <= conteo->size_a /2)
		movimientos = i;
	else
		movimientos = conteo->size_a - i;
	if (numero_stack > stack_b[0] && numero_stack < stack_b[conteo->size_b -1])
	{
		if (movimientos < conteo->movimientos)
		{
			conteo->movimientos = movimientos;
			conteo->mejor_opcion = numero_stack;
		}
		return;
	}
	while (!(numero_stack > stack_b[j] && numero_stack < stack_b[j -1]))
		j++;
	if (j <= conteo->size_b /2 && i <= conteo->size_a / 2)
	{
		if (i <= j)
			movimientos = j;
		else
			movimientos = i;
	}
	if (j > conteo->size_b / 2 && i > conteo->size_a / 2)
	{
		i = conteo->size_a - i;
		j = conteo->size_b -j;
		if (i <= j)
			movimientos = j;
		else
			movimientos = i;
	}
	if (i > conteo->size_a /2 && j <= conteo->size_b /2)
		movimientos = j + (conteo->size_a - i);
	if (i <= conteo->size_a /2 && j > conteo->size_b /2)
		movimientos = i + (conteo->size_b - j);
	
	if (movimientos < conteo->movimientos)
	{
		conteo->movimientos = movimientos;
		conteo->mejor_opcion = numero_stack;
	}
}
/*void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo)
{
    int movimientos_min;
	int movimientos_max;
	
	movimientos_min = numero_movimientos_min(stack_a, stack_b, conteo);
    movimientos_max = numero_movimientos_max(stack_a, stack_b, conteo);
	if (movimientos_min < movimientos_max)
		posicionamiento_min(stack_a, stack_b, conteo);
	else
		posicionamiento_max(stack_a, stack_b, conteo);
}*/
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
		return(conteo->size_a - n);
	}
}

int movimientos_a_realizar_stack_b_min(int *stack_b, t_conteo *conteo)
{
	int	n;

	n = 0;
	if (conteo->size_b == 0)
		return (0);
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




