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

void	base_push_swap(int *stack_a, int *stack_b, int *stack_temp,
	t_conteo *conteo)
{
	if (conteo->size_a <= 5)
	{
		if (conteo->size_a == 3)
			tres_numeros(stack_a, conteo);
		else if (conteo->size_a == 2)
		{
			if (stack_a[0] > stack_a[1])
				sa(stack_a, conteo->size_a);
		}
		else if (conteo->size_a == 4 || conteo->size_a == 5)
			cinco_numeros(stack_a, stack_b, conteo);
	}
	copiar_stack_a(stack_a, stack_temp, conteo);
	ordenar_stack_temp(stack_temp, conteo);
	indexar_stack_a(stack_a, stack_temp, conteo);
	calcular_bits(conteo);
	while (conteo->pivote < conteo->num_bits && !check(stack_a, conteo))
		radix_sort(stack_a, stack_b, conteo);
	devolver_stack_a(stack_a, stack_temp, conteo);
	liberar_memoria(stack_a, stack_b, stack_temp);
}

void	tres_numeros(int *stack_a, t_conteo *conteo)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[2] > stack_a[0])
		sa(stack_a, conteo->size_a);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
	{
		sa(stack_a, conteo->size_a);
		rra(stack_a, conteo->size_a);
	}
	else if (stack_a[0] > stack_a[2] && stack_a[1] < stack_a[2])
		ra(stack_a, conteo->size_a);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[2] > stack_a[0])
	{
		sa(stack_a, conteo->size_a);
		ra(stack_a, conteo->size_a);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2])
		rra(stack_a, conteo->size_a);
}

void	cinco_numeros(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (conteo->size_a > 3)
	{
		conteo->num_min = ft_numero_minimo(stack_a, conteo);
		control_posicion_minimo(stack_a, conteo, conteo->size_a);
		if (conteo->pos_min == 1)
			while (stack_a[0] != conteo->num_min)
				ra(stack_a, conteo->size_a);
		else
			while (stack_a[0] != conteo->num_min)
				rra(stack_a, conteo->size_a);
		pb(stack_a, stack_b, conteo);
	}
	tres_numeros(stack_a, conteo);
	pa(stack_a, stack_b, conteo);
	pa(stack_a, stack_b, conteo);
}

int	ft_numero_minimo(int *stack_a, t_conteo *conteo)
{
	int	min;
	int	i;

	i = 0;
	min = stack_a[0];
	while (i < conteo->size_a)
	{
		if (stack_a[i] < min)
			min = stack_a[i];
		i++;
	}
	return (min);
}
