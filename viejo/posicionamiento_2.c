/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posicionamiento_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:23:37 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/15 14:49:34 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	mover_minimo(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	k;

	k = 0;
	if ((conteo->num_min > stack_b[0] && conteo->num_min < stack_b[conteo->size_b -1]))
	{
		k = 1;
		while (!(stack_b[k] > conteo->num_min && stack_b[k -1] < conteo->num_min))
			k++;
	}
	if (conteo->pos_min == 1 && k <= conteo->size_b /2)
		mover_rr_min(stack_a, stack_b, conteo);
	else if (conteo->pos_min == 2 && k > conteo->size_b /2)
		mover_rrr_min(stack_a, stack_b, conteo);
	else
		mover_r_min(stack_a, stack_b, conteo);
}

void	mover_rr_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if ((stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	while (stack_a[0] != conteo->num_min && !(conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_min && (conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		ra(stack_a, conteo->size_a);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	mover_rr_min_2(stack_a, stack_b, conteo);
}

void	mover_rr_min_2(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] == conteo->num_min && !(conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		rb(stack_b, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	pb(stack_a, stack_b, conteo);
}

void	mover_rrr_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	while (stack_a[0] != conteo->num_min && !(conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		rrr(stack_a, stack_b, conteo);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	while (stack_a[0] != conteo->num_min && (conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		rra(stack_a, conteo->size_a);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	mover_rrr_min_2(stack_a, stack_b, conteo);
}

void	mover_rrr_min_2(int *stack_a, int *stack_b, t_conteo *conteo)
{
	while (stack_a[0] == conteo->num_min && !(conteo->num_min > stack_b[0]
		&& conteo->num_min < stack_b[conteo->size_b -1]))
	{
		rrb(stack_b, conteo->size_b);
		if (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1]
			&& stack_a[0] != conteo->num_min)
			pb(stack_a, stack_b, conteo);
	}
	pb(stack_a, stack_b, conteo);
}
