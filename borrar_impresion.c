#include "push_swap.h"
#include <stdio.h>
#include "libft.h"

void imprimir_stacks(int *stack_a, int *stack_b, t_conteo *conteo)
{
	FILE *archivo = fopen("movimientos.txt", "a");  // 🔁 Abrir en modo append

	if (!archivo)
	{
		perror("No se pudo abrir el archivo movimientos.txt");
		return;
	}

	fprintf(archivo, "\n=== Estado de los stacks ===\n");

	fprintf(archivo, "Stack A (size: %d):\n", conteo->size_a);
	for (int i = 0; i < conteo->size_a; i++)
		fprintf(archivo, "  A[%d] = %d\n", i, stack_a[i]);

	fprintf(archivo, "Stack B (size: %d):\n", conteo->size_b);
	for (int i = 0; i < conteo->size_b; i++)
		fprintf(archivo, "  B[%d] = %d\n", i, stack_b[i]);

	fprintf(archivo, "===========================\n\n");

	fclose(archivo);
}

void limpiar_archivo_movimientos(void)
{
	FILE *archivo = fopen("movimientos.txt", "w");
	if (archivo)
		fclose(archivo);
}

