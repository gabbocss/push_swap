#include "libft.h"
void    base_push_swap(int *stack_a, int *stack_b, int argc, t_conteo *conteo)
{
	int i = 0;
	int n = 0;
	
	conteo->size_a = argc -1;
	conteo->size_b = 0;
	while (conteo->size_a > 0)
		posicionamiento(stack_a, stack_b, conteo);
	if (conteo->size_a == 0)
	{
		ft_printf("entro al if");
		while (conteo->size_b >= 1)
			pa(stack_a, stack_b, conteo);
		guardar_stack_en_archivo(stack_a, conteo->size_a);
			return;
	}
	else
		ft_printf("Error1");
}
