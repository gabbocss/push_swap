#include "libft.h"

int *alocacion_memoria(int argc, char *argv[])
{
    int i;
    int *stack;
    
    i = 1;
    stack = (int*)calloc(argc -1, sizeof(int));
    if (!stack)
        ft_printf("error de memoria pila 1");
    while(i < argc)
    {
        stack[i -1] = ft_atoi(argv[i]);
        i++;
    }
    return (stack);
}
int *alocacion_memoria2(int argc)
{
    int i;
    int *stack;
    
    i = 1;
    stack = (int*)calloc(argc -1, sizeof(int));
    if(!stack)
        ft_printf("Error de memoria pila 2");    
    return (stack);
}