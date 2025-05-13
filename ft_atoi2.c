/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:43:15 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/12 14:39:27 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	signo(const char *nptr, int i)
{
	if (nptr[i] == '-')
		return (-1);
	else
		return (1);
}

/*static int	calculas_numero(const char *nptr, int i)
{
	int		numero;

	numero = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		numero *= 10;
		numero += nptr[i] - '0';
		i++;
	}
	return (numero);
}*/

int	ft_atoi2(const char *nptr)
{
	int		i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (!(nptr[i] == '-' || nptr[i] == '+' || (nptr[i] >= '0' 
		&& nptr[i] <= '9')))
    	return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	
	return (1);
}
