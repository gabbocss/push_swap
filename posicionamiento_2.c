/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posicionamiento_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:23:37 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/12 14:39:53 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	movimientos_a_realizar_stack_a_max(int *stack_a, t_conteo *conteo)
{
	int	n;

	n = 0;
	while (conteo->num_max_a != stack_a[n] && n < conteo->size_a)
		n++;
	if (n <= conteo->size_a / 2)
	{
		conteo->rra_max = 1;
		return (n);
	}
	else
	{
		conteo->rra_max = 2;
		return (conteo->size_a - n);
	}
}

int	movimientos_a_realizar_stack_b_max(int *stack_b, t_conteo *conteo)
{
	int	n;

	n = 0;
	if (conteo->size_b == 0)
		return (0);
	while (conteo->num_max_a < stack_b[n])
		n++;
	if (n <= conteo->size_b / 2)
	{
		conteo->rrb_max = 1;
		return (n);
	}
	else
	{
		conteo->rrb_max = 2;
		return (conteo->size_b - n);
	}
}
