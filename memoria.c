/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoria.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:19:28 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/27 16:19:29 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	*alocacion_memoria(int size_a, char *argv[])
{
	int	i;
	int	*stack;

	i = 0;
	stack = (int *)malloc(sizeof(int) * size_a +1);
	if (!stack)
		ft_printf ("Error\n");
	while (i < size_a)
	{
		stack[i] = ft_atoi(argv[i +1]);
		i++;
	}
	return (stack);
}

int	*alocacion_memoria2(int size_a)
{
	int	*stack;

	stack = (int *)malloc(sizeof(int) * size_a +1);
	if (!stack)
		ft_printf ("Error\n");
	return (stack);
}
