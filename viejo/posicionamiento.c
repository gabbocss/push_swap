#include "libft.h"
#include "push_swap.h"

void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	max;
	int min;
	int	num;

	conteo->num_min = ft_numero_minimo(stack_a, conteo->size_a);
	conteo->num_max_a = ft_numero_maximo(stack_a, conteo->size_a);
	max = numero_movimientos_max(stack_a, stack_b, conteo);
	min = numero_movimientos_min(stack_a, stack_b, conteo);
	num = numero_movimientos_num(stack_a, stack_b, conteo);
	if (min < max && min < num)
		mover_minimo(stack_a, stack_b, conteo);
	else if (max < min && max < num)
		mover_maximo(stack_a, stack_b, conteo);
	else if (num == min)
		mover_num(stack_a, stack_b, conteo);
	else if (max == min)
		mover_maximo(stack_a, stack_b, conteo);
	else if (num == max)
		mover_num(stack_a, stack_b, conteo);
	else if (num < max && num < min)
		mover_num(stack_a, stack_b, conteo);
	return;
}

int	numero_movimientos_max(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	control_posicion_maximo(stack_a, conteo);
	while (stack_a[i] != conteo->num_max_a)
		i++;
	if (!(conteo->num_max_a > stack_b[0] && conteo->num_max_a < stack_b[conteo->size_b -1]))
	{
		k = 1;
		while (!(stack_b[k] < conteo->num_max_a && stack_b[k -1] > conteo->num_max_a))
			k++;
	}
	if (k > conteo->size_b / 2 && i > conteo->size_a /2)
	{
		i = conteo->size_a - i;
		k = conteo->size_b - i;
		if (i > k)
			return (i);
		else
			return (k);
	}
	return (numero_movimientos_max_1(conteo, i, k));
}

int	numero_movimientos_max_1(t_conteo *conteo, int i, int k)
{
	if (k <= conteo->size_b / 2 && i <= conteo->size_a /2)
	{
		if (i > k)
			return (i);
		else
			return (k);
	}
	else
	{
		if (i > conteo->size_a /2)
			i = conteo->size_a -i;
		if (k > conteo->size_b /2)
			k = conteo->size_b -k;
		return (i + k);
	}
}

int	numero_movimientos_min(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	control_posicion_minimo(stack_a, conteo, conteo->size_a);
	while (stack_a[i] != conteo->num_min)
		i++;
	if (!(conteo->num_min > stack_b[0] && conteo->num_min < stack_b[conteo->size_b -1]))
	{
		k = 1;
		while (!(stack_b[k] < conteo->num_min && stack_b[k -1] > conteo->num_min))
			k++;
	}
	if (k > conteo->size_b / 2 && i > conteo->size_a /2)
	{
		i = conteo->size_a - i;
		k = conteo->size_b - k;
		if (i > k)
			return (i);
		else
			return (k);
	}
	return (numero_movimientos_min_1(conteo, i, k));
}

int	numero_movimientos_min_1(t_conteo *conteo, int i, int k)
{
	if (k <= conteo->size_b / 2 && i <= conteo->size_a /2)
	{
		if (i > k)
			return (i);
		else
			return (k);
	}
	else
	{
		if (i > conteo->size_a /2)
			i = conteo->size_a -i;
		if (k > conteo->size_b /2)
			k = conteo->size_b -k;
		return (i + k);
	}
}

