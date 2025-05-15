/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:23 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/12 16:19:05 by inbauman         ###   ########.fr       */
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
	t_conteo	conteo;
	char **args;
 	int arg_count;

	if (!preparar_argumentos(argc, argv, &args, &arg_count))
		return (0);
	limpiar_archivo_movimientos();
	control = 1;
	inicializar_conteo(&conteo);
	control = dimensiones_int(arg_count, args);
	if (control == 0)
		return (1);
	stack_a = alocacion_memoria(arg_count, args);
	stack_b = alocacion_memoria2(arg_count);
	control = control_numeros(arg_count, args);
	if (control == 0)
		return (1);
	control = control_duplicados(stack_a, arg_count);
	if (control == 0)
		return (1);
	base_push_swap(stack_a, stack_b, arg_count, &conteo);
	free(stack_a);
	free(stack_b);
}
