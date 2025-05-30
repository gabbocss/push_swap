/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberar_memoria.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:54:46 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/29 17:54:48 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	liberar_memoria(int *stack_a, int *stack_b, int *stack_temp)
{
	free(stack_a);
	free(stack_b);
	free(stack_temp);
}
