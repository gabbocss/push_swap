/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:23 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/15 18:54:58 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			control;
	int			*stack_a;
	int			*stack_b;
	int			*stack_temp;
	t_conteo	conteo;
	if (argc <=2)
		return (1);
	control = 1;
	inicializar_conteo(&conteo);
	conteo.size_a = argc -1;
	control = dimensiones_int(conteo.size_a, argv);
	if (control == 0)
		return (1);
	stack_a = alocacion_memoria(conteo.size_a, argv);
	stack_b = alocacion_memoria2(conteo.size_a);
	stack_temp = alocacion_memoria2(conteo.size_a);
	control = control_numeros(conteo.size_a, argv);
	if (control == 0)
		return (1);
	control = control_duplicados(stack_a, conteo.size_a);
	if (control == 0)
		return (1);
	base_push_swap(stack_a, stack_b, stack_temp, &conteo);
	free(stack_a);
	free(stack_b);
	free(stack_temp);
}
