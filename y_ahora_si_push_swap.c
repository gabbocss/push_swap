/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_ahora_si_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:26:53 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/12 20:47:34 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	base_push_swap(int *stack_a, int *stack_b, int argc, t_conteo *conteo)
{
	int	i;

	i = 0;
	conteo->size_a = argc;
	conteo->size_b = 0;
	if (conteo->size_b < 2)
	{
		pb(stack_a, stack_b, conteo);
		pb(stack_a, stack_b, conteo);
		if (stack_b[0] < stack_b[1])
			sb(stack_b, conteo->size_b);
		while(i < conteo->size_b)
		{
			ft_printf("stack_b[%i] == %i\n", i, stack_b[i]);
			i++;
		}
		
	}
	posicionar_limites(stack_a, stack_b, conteo);
	while (conteo->size_a >= 4)
	{
		conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
		while (stack_a[0] > stack_b[0]
			&& stack_a[0] < stack_b[conteo->size_b -1])
		{
			pb(stack_a, stack_b, conteo);
			conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
		}
		posicionamiento(stack_a, stack_b, conteo);
		conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
		
	}
	i = 0;
	ft_printf("\nstack_a[0] == %i\nstack_a[1] == %i\nstack_a[2] == %i\nconteo->size_a == %i\n\n", stack_a[0], stack_a[1],stack_a[2], conteo->size_a);
	while(i < conteo->size_b)
	{
		ft_printf("stack_b[%i] == %i\n", i, stack_b[i]);
		i++;
	}
	int min;
	int pos;
	conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];
	if (conteo->size_a == 3)
	{
	if (a > b && b > c)
	{
		sa(stack_a, conteo->size_a);
		rra(stack_a, conteo->size_a);
	}
	else if (a > c && c > b)
		ra(stack_a, conteo->size_a);
	else if (b > a && a > c)
		rra(stack_a, conteo->size_a);
	else if (b > c && c > a)
		sa(stack_a, conteo->size_a);
	else if (c > a && a > b)
	{
		sa(stack_a, conteo->size_a);
		//ra(stack_a, conteo->size_a);
	}
	}
	i = 0;
	ft_printf("\nstack_a[0] == %i\nstack_a[1] == %i\nstack_a[2] == %i\nconteo->size_a == %i\n\n", stack_a[0], stack_a[1],stack_a[2], conteo->size_a);
	while(i < conteo->size_b)
	{
		ft_printf("stack_b[%i] == %i\n", i, stack_b[i]);
		i++;
	}
	if (conteo->size_a == 2 && stack_a[0] > stack_a[1])
	{
		sa(stack_a, conteo->size_a);
	}


	
    //ft_printf("\nstack_a[0] == %i\nstack_a[1] == %i\nstack_a[2] == %i\nconteo->size_a == %i\n\n", stack_a[0], stack_a[1],stack_a[2], conteo->size_a);
	//ft_printf("ahora\n");
	//ft_printf("conteo->size_a == %i\n", conteo->size_a);
	if (conteo->size_a <= 10)
	{
	
		conteo->num_min = ft_numero_minimo(stack_b, conteo->size_b);
		control_posicion_minimo(stack_b, conteo, conteo->size_b);
		while (conteo->num_min != stack_b[conteo->size_b -1])
		{
			if (conteo->pos_min == 1)
				rb(stack_b, conteo->size_b);
			if (conteo->pos_min == 2)
				rrb(stack_b, conteo->size_b);
		}
		while (conteo->size_b >= 1)
		{
			conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
			while(stack_b[0] < stack_a[conteo->size_a -1] && stack_a[conteo->size_a -1] != conteo->num_max_a)
				rra(stack_a, conteo->size_a);
			ft_printf("1\n");	
			pa(stack_a, stack_b, conteo);
			
		}
			
		guardar_stack_en_archivo(stack_a, conteo->size_a);
			return;
	}
}

void	posicionar_limites(int *stack_a, int *stack_b, t_conteo *conteo)
{
	
	conteo->num_min = ft_numero_minimo(stack_a, conteo->size_a);
	conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
	control_posicion_minimo(stack_a, conteo, conteo->size_b);
	while (conteo->num_min != stack_a[0] && conteo->pos_min == 1)
	{
		while (stack_a[0] > stack_b[0] && stack_a[0] != conteo->num_max_a)
			pb(stack_a, stack_b, conteo);
		if (stack_a[0] == conteo->num_min)
			break;
		ra(stack_a, conteo->size_a);
	}
	while (conteo->num_min != stack_a[0] && conteo->pos_min == 2)
	{
		while (stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
			pb(stack_a, stack_b, conteo);
		if (stack_a[0] == conteo->num_min)
			break;
		rra(stack_a, conteo->size_a);
	}	
	pb(stack_a, stack_b, conteo);
	control_posicion_maximo(stack_a, conteo);
	int i = 0;
	while (i <= conteo->size_a)
	{
		if (stack_a[i] == conteo->num_max_a)
		{
			while (conteo->num_max_a != stack_a[0] || conteo->num_min != stack_b[conteo->size_b -1] && conteo->pos_max == 1)
			{
				while (conteo->num_max_a != stack_a[0] && stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
					pb(stack_a, stack_b, conteo);
				if (stack_a[0] != conteo->num_max_a && conteo->num_min != stack_b[conteo->size_b -1])
					rr(stack_a, stack_b, conteo->size_a, conteo->size_b);
				if (stack_a[0] != conteo->num_max_a && conteo->num_min == stack_b[conteo->size_b -1])
				{
			
					ft_printf("aqui");
					ra(stack_a, conteo->size_a);
				}
			
			if (stack_a[0] == conteo->num_max_a && conteo->num_min != stack_b[conteo->size_b -1]){
			//ft_printf("aqui");
			rb(stack_b, conteo->size_b);}
			}
			
			while (conteo->num_max_a != stack_a[0] || conteo->num_min != stack_b[conteo->size_b -1] && conteo->pos_max == 2)
			{
				//ft_printf("conteo->num_min == %i", conteo->num_min);
				while (conteo->num_max_a != stack_a[0] && stack_a[0] > stack_b[0] && stack_a[0] < stack_b[conteo->size_b -1])
					pb(stack_a, stack_b, conteo);
				if (stack_a[0] != conteo->num_max_a && conteo->num_min != stack_b[conteo->size_b -1])
					rrr(stack_a, stack_b, conteo);
				if (stack_a[0] != conteo->num_max_a && conteo->num_min == stack_b[conteo->size_b -1])
				{
					//ft_printf("aqui");
					rra(stack_a, conteo->size_a);
				}
			
				if (stack_a[0] == conteo->num_max_a && conteo->num_min != stack_b[conteo->size_b -1])
				{
					//ft_printf("aqui");
					rrb(stack_b, conteo->size_b);
				}
			}
		}
		i++;
	}
	pb(stack_a, stack_b, conteo);
	/*int i = 0;
		ft_printf("\nstack_a[0] == %i\n\n", stack_a[0], stack_b[0]);
		while(i < conteo->size_b)
		{
			ft_printf("stack_b[%i] == %i\n", i, stack_b[i]);
			i++;
		}*/
	//ft_printf("aqui maximo");
}

