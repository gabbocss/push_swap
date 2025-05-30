/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:28:46 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/15 18:30:32 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_numero_maximo(int *stack_a, int argc)
{
	int	i;
	int	max;

	i = 0;
	max = stack_a[0];
	while (i < argc)
	{
		if (stack_a[i] > max)
			max = stack_a[i];
		i++;
	}
	return (max);
}

int	control_numeros(int argc, char *argv[])
{
	int	control;
	int	i;

	i = 1;
	control = 1;
	while (i <= argc -1)
	{
		control = ft_atoi2(argv[i]);
		if (control == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	control_duplicados(int *stack1, int argc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < argc - 1)
	{
		j = i +1;
		while (j < argc)
		{
			if (stack1[i] == stack1[j])
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	dimensiones_int(int argc, char *argv[])
{
	int	i;
	int	b;

	i = 1;
	b = 1;
	while (i <= argc)
	{
		b = ft_atoi3(argv[i]);
		if (b == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
