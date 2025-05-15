/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:23 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/15 18:54:58 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void guardar_stack_en_archivo(int *stack_a, int size_a)
{
    FILE *archivo = fopen("stack_ordenado.txt", "w");  // 📂 Abrimos archivo en modo escritura

    if (!archivo)  // ❌ Si el archivo no se puede abrir, mostramos un error
    {
        //perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < size_a; i++)  // 🔄 Guardamos cada número en el archivo
    {
        fprintf(archivo, "%d\n", stack_a[i]);
    }

    fclose(archivo);  // 📌 Cerramos el archivo
    //printf("✅ Stack ordenado guardado en 'stack_ordenado.txt'\n");
}

int	main(int argc, char *argv[])
{
	int			control;
	int			*stack_a;
	int			*stack_b;
	int			*stack_temp;
	t_conteo	conteo;
	
	control = 1;
	inicializar_conteo(&conteo);
	conteo.size_a = argc -1;
	control = dimensiones_int(conteo.size_a, argv);
	if (control == 0)
		return (1);
	stack_a = alocacion_memoria(conteo.size_a, argv);
	stack_b = alocacion_memoria2(conteo.size_a);
	stack_temp = alocacion_memoria2(conteo.size_a);
	control = control_numeros(conteo.size_a, argv);
	if (control == 0)
		return (1);
	control = control_duplicados(stack_a, conteo.size_a);
	if (control == 0)
		return (1);
	base_push_swap(stack_a, stack_b, stack_temp, &conteo);
	//base_push_swap(stack_a, stack_b, &conteo, argc);
	free(stack_a);
	free(stack_b);
	free(stack_temp);
}
