/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuevo_ps_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:22:43 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/29 17:22:44 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	copiar_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo)
{
	int	i;

	i = 0;
	while (i < conteo->size_a)
	{
		stack_temp[i] = stack_a[i];
		i++;
	}
}

void	ordenar_stack_temp(int *stack_temp, t_conteo *conteo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < conteo->size_a -1)
	{
		if (stack_temp[i +1] < stack_temp[i])
		{
			j = stack_temp[i];
			stack_temp[i] = stack_temp[i +1];
			stack_temp[i +1] = j;
			i = -1;
		}
		i++;
	}	
}

void	indexar_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < conteo->size_a)
	{
		while (stack_a[i] != stack_temp[j])
			j++;
		stack_a[i] = j;
		j = 0;
		i++;
	}
}

void	calcular_bits(t_conteo *conteo)
{
	int	num_max;

	num_max = conteo->size_a -1;
	while ((num_max >> (conteo->num_bits)) != 0)
		conteo->num_bits++;
}

void	radix_sort(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	j;
	int	max;
	int	grupo;

	grupo = 0;
	j = 0;
	max = conteo->size_a;
	while (j < max)
	{
		grupo = (stack_a[0] >> conteo->pivote) & 1;
		if (grupo == 0)
			pb(stack_a, stack_b, conteo);
		else
			ra(stack_a, conteo->size_a);
		j++;
	}
	while (conteo->size_b > 0)
		pa(stack_a, stack_b, conteo);
	conteo->pivote++;
	conteo->check = check(stack_a, conteo);
}
