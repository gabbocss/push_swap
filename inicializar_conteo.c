/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializar_conteo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:58:45 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/12 14:58:48 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inicializar_conteo(t_conteo *conteo)
{
	conteo->size_a = 0;
	conteo->size_b = 0;
	conteo->rra_min = 0;
	conteo->rra_max = 0;
	conteo->rrb_min = 0;
	conteo->rrb_max = 0;
	conteo->num_min = 0;
	conteo->num_max_a = 0;
	conteo->pos_min = 0;
	conteo->pos_max = 0;
	conteo->pivote = 0;
	conteo->movimientos = 0;
	conteo->mejor_opcion = 0;
	conteo->num_max_b = 0;
}
