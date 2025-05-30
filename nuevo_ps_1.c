/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuevo_ps_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:24:18 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/29 17:24:20 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check(int *stack_a, t_conteo *conteo)
{
	int	i;

	i = 0;
	while (i < conteo->size_a -1)
	{
		if (stack_a[i] > stack_a[i +1])
			return (0);
		i++;
	}
	return (1);
}

void	devolver_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo)
{
	int	i;

	i = 0;
	while (i < conteo->size_a)
	{
		stack_a[i] = stack_temp[i];
		i++;
	}
}
