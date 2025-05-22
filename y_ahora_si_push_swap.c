/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_ahora_si_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:26:53 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/15 19:36:03 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	base_push_swap(int *stack_a, int *stack_b, int *stack_temp, t_conteo *conteo)
{
	copiar_stack_a(stack_a, stack_temp, conteo);
	ordenar_stack_temp(stack_temp, conteo);
	indexar_stack_a(stack_a, stack_temp, conteo);
	calcular_bits(stack_temp, conteo);
 	while (conteo->pivote < conteo->num_bits && !check(stack_a, conteo))
		radix_sort(stack_a, stack_b, conteo);
	//guardar_stack_en_archivo(stack_a, conteo->size_a);
	/*int i = 0;
	while (i < conteo->size_a)
	{
		ft_printf("stack_a[%i] == %i\n", i, stack_a[i]);
		i++;
	}*/

}

int	is_sorted(int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0); // No está ordenado
		i++;
	}
	return (1); // Sí está ordenado
}

































/*void	base_push_swap(int *stack_a, int *stack_b, t_conteo *conteo, int argc)
{
	int	i;

	i = 0;
	conteo->size_a = argc -1;
	conteo->size_b = 0;
	// se inician aqui porque si el maximo esta entre los dos primeros numeros "posicionar_limites da error"
	conteo->num_min = ft_numero_minimo(stack_a, conteo->size_a);
	conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
	if (conteo->size_b < 2)
	{
		pb(stack_a, stack_b, conteo);
		pb(stack_a, stack_b, conteo);
		if (stack_b[0] < stack_b[1])
			sb(stack_b, conteo->size_b);
	}
	posicionar_limites(stack_a, stack_b, conteo);
	
	while (conteo->size_a >= 4)
		posicionamiento(stack_a, stack_b, conteo);
	
	i = 0;
	int min;
	int pos;
	
	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];
	if (conteo->size_a == 3)
	{
		int a = stack_a[0];
		int b = stack_a[1];
		int c = stack_a[2];
	
		if (a > b && b > c)
		{
			sa(stack_a, conteo->size_a);
			rra(stack_a, conteo->size_a);
		}
		else if (a > c && c > b)
			ra(stack_a, conteo->size_a);
		else if (b > a && a > c)
			rra(stack_a, conteo->size_a);
		else if (b > c && c > a)
		{
			sa(stack_a, conteo->size_a);
			ra(stack_a, conteo->size_a);
		}
		else if (c > a && a > b)
		{
			sa(stack_a, conteo->size_a);
			ra(stack_a, conteo->size_a);
		}
	}
	else if (conteo->size_a == 2 && stack_a[0] > stack_a[1])
		sa(stack_a, conteo->size_a);	
	if (conteo->size_a <= 10)
	{
	
		conteo->num_min = ft_numero_minimo(stack_b, conteo->size_b);
		control_posicion_minimo(stack_b, conteo, conteo->size_b);
		while (conteo->num_min != stack_b[conteo->size_b -1])
		{
			if (conteo->pos_min == 1)
				rb(stack_b, conteo->size_b);
			if (conteo->pos_min == 2)
				rrb(stack_b, conteo->size_b);
		}
		while (conteo->size_b >= 1)
		{
			conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
			while(stack_b[0] < stack_a[conteo->size_a -1] && stack_a[conteo->size_a -1] != conteo->num_max_a)
				rra(stack_a, conteo->size_a);
			pa(stack_a, stack_b, conteo);
			
		}
		guardar_stack_en_archivo(stack_a, conteo->size_a);
			return;
	}
}

void	posicionar_limites(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (!check_limites_minimo(conteo, stack_b))
	{
		control_posicion_minimo(stack_a, conteo, conteo->size_b);
		while (conteo->num_min != stack_a[0] && conteo->pos_min == 1)
		{
			while (stack_a[0] > stack_b[0] && stack_a[0] != conteo->num_max_a)
				pb(stack_a, stack_b, conteo);
			if (stack_a[0] == conteo->num_min)
				break;
			ra(stack_a, conteo->size_a);
		}
		while (conteo->num_min != stack_a[0] && conteo->pos_min == 2)
		{
			while (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
				pb(stack_a, stack_b, conteo);
			if (stack_a[0] == conteo->num_min)
				break;
			rra(stack_a, conteo->size_a);
		}	
		pb(stack_a, stack_b, conteo);
		rb(stack_b, conteo->size_b);
	}
	
	if (!check_limites_maximo(conteo, stack_b))
	{
		control_posicion_maximo(stack_a, conteo);
		while (conteo->num_max_a != stack_a[0])
		{
			if (conteo->pos_max == 1)
			{
					while (conteo->num_max_a != stack_a[0] && stack_a[0] > stack_b[0])
						pb(stack_a, stack_b, conteo);
					if (stack_a[0] != conteo->num_max_a)
						ra(stack_a, conteo->size_a);
			}
			if (conteo->pos_max == 2)
			{
				while (conteo->num_max_a != stack_a[0] && stack_a[0] > stack_b[0])
					pb(stack_a, stack_b, conteo);
				if (stack_a[0] != conteo->num_max_a)
					rra(stack_a, conteo->size_a);
			}
		}
		pb(stack_a, stack_b, conteo);
	}
		
}*/


