#include "libft.h"
#include "push_swap.h"

void    rra(int *stack_a, int size_a)
{
    int temp;
	int	i;

	i = size_a -1;
    temp = stack_a[size_a -1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i -1];
		i--;
	}
	stack_a[0] = temp;
	ft_printf("rra\n");
}

void	rrb(int *stack_b, int size_b)
{
	int	temp;
	int	i;

	i = size_b -1;
	temp = stack_b[size_b -1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i -1];
		i--;
	}
	stack_b[0] = temp;
	ft_printf("rrb\n");
}
void	rrr(int *stack_a, int *stack_b, t_conteo *conteo)
{
	int temp;
	int	i;

	i = conteo->size_a -1;
    temp = stack_a[conteo->size_a -1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i -1];
		i--;
	}
	stack_a[0] = temp;
	i = conteo->size_b -1;
    temp = stack_b[conteo->size_b -1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i -1];
		i--;
	}
	stack_b[0] = temp;
	ft_printf("rrr\n");
}