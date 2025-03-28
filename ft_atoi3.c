#include "libft.h"
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

int ft_atoi3(const char *nptr)
{
	long		numero;
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
    if (numero * negativo < INT_MIN
        || numero * negativo > INT_MAX)
        return (0);
	return (1);
}
