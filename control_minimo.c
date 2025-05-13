#include "libft.h"
#include "push_swap.h"

void    control_posicion_minimo(int *stack, t_conteo *conteo, int size)
{
    int n;

    n = 0;
    while (conteo->num_min != stack[n])
    {
        if (n == size -1)
            break;
        n++;
    }
    if (n <= size / 2)
        conteo->pos_min = 1;
    else
        conteo->pos_min = 2;
}

void    control_posicion_maximo(int *stack, t_conteo *conteo)
{
    int n;

    n = 0;
    while (conteo->num_max_a != stack[n])
    {
        if (n == conteo->size_a -1)
            break;
        n++;
    }
    if (n <= conteo->size_a / 2)
        conteo->pos_max = 1;
    else
        conteo->pos_max = 2;
}


