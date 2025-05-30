/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_limites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:17 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/27 16:05:21 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	check_limites_minimo(t_conteo *conteo, int *stack_b)
{
	int	i;

	i = 0;
	while (i < conteo->size_b)
	{
		if (stack_b[i] == conteo->num_min)
			return (1);
		i++;
	}
	return (0);
}

int	check_limites_maximo(t_conteo *conteo, int *stack_b)
{
	int	i;

	i = 0;
	while (i < conteo->size_b)
	{
		if (stack_b[i] == conteo->num_max_a)
			return (1);
		i++;
	}
	return (0);
}
