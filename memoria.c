#include "libft.h"
#include "push_swap.h"

int *alocacion_memoria(int size_a, char *argv[])
{
    int i;
    int *stack;
    
    i = 0;
    stack = (int *)malloc(sizeof(int) * size_a);
    if (!stack)
        ft_printf("error de memoria pila 1");
    while(i < size_a)
    {
        stack[i] = ft_atoi(argv[i +1]);
        i++;
    }
    return (stack);
}
int *alocacion_memoria2(int size_a)
{
    //int i;
    int *stack;
    
    //i = 1;
    stack = (int *)malloc(sizeof(int) * size_a);
    if(!stack)
        ft_printf("Error de memoria pila 2");    
    return (stack);
}