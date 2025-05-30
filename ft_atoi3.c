/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:14:52 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/27 16:14:55 by inbauman         ###   ########.fr       */
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

static long	calculas_numero(const char *nptr, int i)
{
	long		numero;

	numero = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		numero *= 10;
		numero += nptr[i] - '0';
		i++;
	}
	return (numero);
}

int	ft_atoi3(const char *nptr)
{
	long	numero;
	int		negativo;
	int		i;

	i = 0;
	numero = 0;
	negativo = 0;
	if (nptr[i] == '\0')
		return (0);
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (!(nptr[i] == '-' || nptr[i] == '+' || (nptr[i] >= '0'
				&& nptr[i] <= '9')))
		return (0);
	negativo = signo(nptr, i);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	numero = calculas_numero(nptr, i);
	if (numero * negativo < INT_MIN || numero * negativo > INT_MAX)
		return (0);
	return (ft_atoi4(nptr, i));
}

int	ft_atoi4(const char *nptr, int i)
{
	while (nptr[i] != '\0')
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
