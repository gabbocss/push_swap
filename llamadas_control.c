/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llamadas_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:33:49 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/30 16:33:51 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	llamadas_control_0(t_conteo *conteo, char *argv[])
{
	int	control;

	control = 0;
	control = dimensiones_int(conteo->size_a, argv);
	if (control == 0)
		return (0);
	control = control_numeros(conteo->size_a, argv);
	if (control == 0)
		return (0);
	return (1);
}

int	llamadas_control_1(int *stack_a, t_conteo *conteo)
{
	int	control;

	control = 0;
	control = control_duplicados(stack_a, conteo->size_a);
	if (control == 0)
	{
		return (0);
	}
	return (1);
}
