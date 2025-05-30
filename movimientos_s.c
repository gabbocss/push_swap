/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimientos_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:37:02 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/27 16:37:04 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(int *stack_a, int size_a)
{
	int	temp;

	if (size_a < 2)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_printf ("sa\n");
}

void	sb(int *stack_b, int size_b)
{
	int	temp;

	if (size_b < 2)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf ("sb\n");
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	temp;

	if (size_a >= 2)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
	if (size_b >= 2)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
	}
	ft_printf ("ss\n");
}
