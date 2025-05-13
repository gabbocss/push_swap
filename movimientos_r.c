#include "libft.h"
#include "push_swap.h"

void    ra(int *stack_a, int size_a)
{
    if (size_a <= 1)
        return;
    int temp;
    int n;

    temp = stack_a[0];
    n = 0;
    while (n <= size_a -1)
    {
        stack_a[n] = stack_a[n +1];
        n++;
    }
    stack_a[size_a -1] = temp;
    ft_printf("ra\n");
}

void    rb(int *stack_b, int size_b)
{
    if (size_b < 1)
        return;
    int temp;
    int n;

    temp = stack_b[0];
    n = 0;
    while (n < size_b -1)
    {
        stack_b[n] = stack_b[n +1];
        n++;
    }
    stack_b[size_b -1] = temp;
    ft_printf("rb\n");
}
void    rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int temp;

    int n;
    temp = stack_a[0];
    n = 0;
    while (n < size_a -1)
    {
        stack_a[n] = stack_a[n +1];
        n++;
    }
    stack_a[size_a -1] = temp;
    temp = stack_b[0];
    n = 0;
    while (n < size_b -1)
    {
        stack_b[n] = stack_b[n +1];
        n++;
    }
    stack_b[size_b -1] = temp;
    ft_printf("rr\n");
}
