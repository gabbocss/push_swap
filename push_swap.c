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

		control = 1;
		inicializar_conteo(&conteo);
		conteo.size_a = argc -1;
	if (argc > 1)
		control = llamadas_control_0(&conteo, argv);
	if (control == 0)
		return (1);
	if (argc <= 2)
		return (1);
	stack_a = alocacion_memoria(conteo.size_a, argv);
	stack_b = alocacion_memoria2(conteo.size_a);
	stack_temp = alocacion_memoria2(conteo.size_a);
	control = llamadas_control_1(stack_a, &conteo);
	if (control == 0)
	{
		liberar_memoria(stack_a, stack_b, stack_temp);
		return (1);
	}
	base_push_swap(stack_a, stack_b, stack_temp, &conteo);
}
