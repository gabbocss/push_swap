#include "libft.h"
#include "push_swap.h"

void    sa(int *stack_a, int size_a)
{
    if (size_a < 2)
        return;
    int temp;

    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;

    ft_printf("sa\n");
}
void sb(int *stack_b, int size_b)
{
    if (size_b < 2)
        return;
    int temp;

    temp = stack_b[0];
    stack_b[0] = stack_b[1];
    stack_b[1] = temp;

    ft_printf("sb\n");
}
void    ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int temp;
    if (size_a >= 2)
    {
        temp = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temp;
    }
    if (size_b >= 2)
    {
        temp = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temp;
    }
    ft_printf("ss\n");
}
