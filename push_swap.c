/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:23 by inbauman          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:01 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int main(int argc, char *argv[])
{
	if (argc ==  2)
		return (1);
    int control;
    int *stack_a;
    int *stack_b;
    t_conteo conteo;
    
    control = 1;
    control = dimensiones_int(argc, argv);
    if (control == 0)
        return(1);
    stack_a = alocacion_memoria(argc, argv);
    stack_b = alocacion_memoria2(argc);
    control = control_numeros(argc, argv);
    if (control == 0)
        return(1);
    control = control_duplicados(stack_a, argc);
    if (control == 0)
        return(1);
    base_push_swap(stack_a, stack_b, argc, &conteo);
    int i = 0;
    free(stack_a);
    free(stack_b);
}
