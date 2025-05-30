/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:37:49 by inbauman          #+#    #+#             */
/*   Updated: 2025/05/29 17:37:52 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_conteo
{
	int	size_a;
	int	size_b;
	int	rra_min;
	int	rra_max;
	int	rrb_min;
	int	rrb_max;
	int	num_min;
	int	num_max_a;
	int	pos_min;
	int	pos_max;
	int	pivote;
	int	movimientos;
	int	mejor_opcion;
	int	num_max_b;
	int	pos_num;
	int	num_bits;
	int	check;
}	t_conteo;

int		control_duplicados(int *stack1, int argc);
int		*alocacion_memoria(int size_a, char *argv[]);
int		*alocacion_memoria2(int size_a);
int		ft_numero_minimo(int *stack_a, t_conteo *conteo);
int		control_numeros(int argc, char *argv[]);
int		ft_atoi2(const char *nptr);
int		ft_atoi3(const char *nptr);
int		dimensiones_int(int argc, char *argv[]);
void	base_push_swap(int *stack_a, int *stack_b,
			int *stack_temp, t_conteo *conteo);
void	sa(int *stack_a, int size_a);
void	sb(int *stack_b, int size_b);
void	ss(int *stack_a, int *stack_b, int size_a,
			int size_b);
void	pb(int *stack_a, int *stack_b, t_conteo *conteo);
void	pa(int *stack_a, int *stack_b, t_conteo *conteo);
void	ra(int *stack_a, int size_a);
void	rb(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rrr(int *stack_a, int *stack_b, t_conteo *conteo);
void	rrb(int *stack_b, int size_b);
void	rra(int *stack_a, int size_a);
void	recolocacion_a_stack_a(int *stack_a, int *stack_b, int size_b);
void	guardar_stack_en_archivo(int *stack_a, int size_a);
void	control_posicion_minimo(int *stack, t_conteo *conteo, int size);
void	posicionar_minimo(int *stack_a, int *size_a,
			int posicion_minimo, int n);
int		ft_numero_maximo(int *stack_a, int argc);
void	posicionamiento(int *stack_a, int *stack_b, t_conteo *conteo);
int		numero_movimientos_min(int *stack_a, int *stack_b, t_conteo *conteo);
int		numero_movimientos_max(int *stack_a, int *stack_b, t_conteo *conteo);
void	posicionamiento_min(int *stack_a, int *stack_b, t_conteo *conteo);
void	posicionamiento_max(int *stack_a, int *stack_b, t_conteo *conteo);
int		movimientos_a_realizar_stack_a_min(int *stack, t_conteo *conteo);
int		movimientos_a_realizar_stack_b_min(int *stack_b, t_conteo *conteo);
int		movimientos_a_realizar_stack_a_max(int *stack_a, t_conteo *conteo);
int		movimientos_a_realizar_stack_b_max(int *stack_b, t_conteo *conteo);
void	posicionar_limites(int *stack_a, int *stack_b, t_conteo *conteo);
void	control_posicion_maximo(int *stack, t_conteo *conteo);
void	ordenar_numeros(int *stack_a, t_conteo *conteo);
void	ordenar_numeros_2(int *temp, int i, t_conteo *conteo);
void	volver_a_stack_a(int *stack_a, int *stack_b, t_conteo *conteo);
void	ordenar_stack_a(int *stack_a, t_conteo *conteo);
void	movimiento_pb(int *stack_a, int *stack_b, t_conteo *conteo);
void	ordenar_stack_a_posicionar_minimo(int *stack_a, t_conteo *conteo);
void	pasar_minimo(int *stack_a, int *stack_b, t_conteo *conteo);
int		calcular_movimiento(int *stack_a, int *stack_b, t_conteo *conteo);
void	movimiento_pa(int *stack_a, int *stack_b, t_conteo *conteo);
void	posicionamiento_mejor_opcion(int *stack_a, int *stack_b,
			t_conteo *conteo);
void	control_jugadas_0(int numero_stack, int *stack_b,
			t_conteo *conteo, int i);
void	control_jugadas(int numero_stack, int *stack_b,
			t_conteo *conteo, int i);
void	pasar_max(int *stack_a, int *stack_b, t_conteo *conteo);
void	inicializar_conteo(t_conteo *conteo);
int		preparar_argumentos(int argc, char **argv, char ***args,
			int *arg_count);
void	free_split(char **split);
int		contar_tokens(char **args);
int		ft_atoi4(const char *nptr, int i);
void	imprimir_stacks(int *stack_a, int *stack_b, t_conteo *conteo);
void	limpiar_archivo_movimientos(void);
int		check_limites_minimo(t_conteo *conteo, int *stack_b);
int		check_limites_maximo(t_conteo *conteo, int *stack_b);
int		numero_movimientos_max_1(t_conteo *conteo, int i, int k);
int		numero_movimientos_min_1(t_conteo *conteo, int i, int k);
void	mover_rr_min(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rrr_min(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rr_min_2(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rrr_min_2(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_r_min(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_r_min_2(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_minimo(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_maximo(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rr_max(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rr_max_2(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rrr_max(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_rrr_max_2(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_r_max(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_r_max_2(int *stack_a, int *stack_b, t_conteo *conteo);
int		numero_movimientos_num(int *stack_a, int *stack_b, t_conteo *conteo);
void	mover_num(int *stack_a, int *stack_b, t_conteo *conteo);
void	copiar_stack_a(int *stack_a, int *stack_b, t_conteo *conteo);
void	ordenar_stack_temp(int *stack_temp, t_conteo *conteo);
void	indexar_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo);
void	calcular_bits(t_conteo *conteo);
void	radix_sort(int *stack_a, int *stack_b, t_conteo *conteo);
int		is_sorted(int *stack_a, int size);
int		check(int *stack_a, t_conteo *conteo);
void	devolver_numeros(int *stack_a, int *stack_b, t_conteo *conteo);
void	quick_sort(int *stack_a, int *stack_b, t_conteo *conteo);
void	liberar_memoria(int *stack_a, int *stack_b, int *stack_temp);
void	devolver_stack_a(int *stack_a, int *stack_temp, t_conteo *conteo);
void	tres_numeros(int *stack_a, t_conteo *conteo);
int		llamadas_control_0(t_conteo *conteo, char *argv[]);
int		llamadas_control_1(int *stack_a, t_conteo *conteo);
void	cinco_numeros(int *stack_a, int *stack_b, t_conteo *conteo);

#endif
